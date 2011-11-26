#include "mainwindow.h"
#include "datalog.h"
#include "googlemapwindow.h"
#include "plotwindow.h"
#include "datastatisticswindow.h"
#include "rideselectionwindow.h"
#include "user.h"
#include "aboutwindow.h"
#include "specifyuserwindow.h"
#include "logdirectorysummary.h"
#include "totalswindow.h"

#include <stdio.h>
#include <iostream>

#include <QLabel.h>
#include <QScrollArea.h>
#include <QScrollBar.h>
#include <QAction.h>
#include <QMenu.h>
#include <QMenuBar.h>
#include <QFileDialog.h>
#include <QMessageBox.h>
#include <QPainter.h>
#include <QApplication.h>
#include <QGridLayout.h>
#include <QDesktopWidget.h>
#include <QBitmap.h>
#include <QListWidget.h>
#include <QInputDialog.h>
#include <QSettings.h>

#define COMPANY_NAME "RideViewer"
#define APP_NAME "RiderViewer"
#define VERSION_INFO "Version 1.0 (Nov 2011)\n     http://code.google.com/p/cycling-data-view/ \n     grant.grubb@gmail.com"
#define USER_DIRECTORY "/riders/"

/******************************************************/
MainWindow::MainWindow():
QMainWindow()
 {
	createActions();
	createMenus();

	_current_user = new User();

	_google_map = new GoogleMapWindow();
	_stats_view = new DataStatisticsWindow();
	_plot_window = new PlotWindow(_google_map, _stats_view);
	_totals_window = 0;

	_ride_selector = new RideSelectionWindow();
	connect(_ride_selector , SIGNAL(displayRide(DataLog*)),this,SLOT(setRide(DataLog*)));
	connect(_ride_selector , SIGNAL(displayLap(int)),this,SLOT(setLap(int)));

	QWidget* central_widget = new QWidget;
	QGridLayout* glayout1 = new QGridLayout(central_widget);
	glayout1->addWidget(_ride_selector,0,0);
	glayout1->addWidget(_plot_window,0,1);
	glayout1->addWidget(_stats_view,1,0, Qt::AlignLeft | Qt::AlignTop);
	glayout1->addWidget(_google_map,1,1);

	setCentralWidget(central_widget);
	setWindowTitle("RideViewer");
	setWindowIcon(QIcon("./resources/rideviewer_head128x128.ico")); 
	
	// Set to full screen size
	showMaximized();

	// Check for saved user from persistent settings
	checkForSaveUser();
 }

/******************************************************/
void MainWindow::checkForSaveUser()
{
	QSettings settings(COMPANY_NAME, APP_NAME);
	if (settings.contains("Rider"))
	{
		QString user_name = settings.value("Rider").toString();
		_current_user->readFromFile(QDir::currentPath() + USER_DIRECTORY + user_name + ".rider");
		setUser(_current_user);
	}
	else
	{
		QMessageBox::information(this, tr("First Start"), tr("Ciao! You need to create a rider profile before using RideViewer."));
		addUser();
	}
}

/******************************************************/
MainWindow::~MainWindow()
{}

/******************************************************/
void MainWindow::closeEvent(QCloseEvent* event) 
{
	// Save current user
	if (!_current_user->name().isEmpty())
	{
		QSettings settings(COMPANY_NAME, APP_NAME);
		settings.setValue("Rider", _current_user->name());
	}

	// Delete members
	delete _google_map;
	delete _plot_window;
	delete _stats_view;
	delete _ride_selector;
	delete _current_user;
	if (_totals_window)
	{
		_totals_window->close();
		delete _totals_window;
	}
}

/******************************************************/
void MainWindow::promptForUser()
{
	QDir directory;
	QStringList filter;
	filter << "*.rider";
	directory.setNameFilters(filter);
	directory.setPath(QDir::currentPath() + USER_DIRECTORY);
	QStringList user_filenames = directory.entryList();

	if (user_filenames.length() > 0)
	{
		// Load the users from file
		std::vector<User*> users;
		QStringList user_names;
		for (int i = 0; i < user_filenames.length(); ++i)
		{
			User* user = new User;
			user->readFromFile(QDir::currentPath() + USER_DIRECTORY + user_filenames[i]);
			users.push_back(user);

			user_names.append(user->name());
		}

		// Prompt to select a user
		bool ok;
		QString	user_name = QInputDialog::getItem(this, tr("Rider Selection"), tr("Select Rider:"), user_names, 0, false, &ok, 0);
		
		// Set the selected user
		if (ok)
			setUser(users[user_names.indexOf(user_name)]);
	}
}

/******************************************************/
void MainWindow::addUser()
{
	SpecifyUserWindow* add_user_window = new SpecifyUserWindow();
	connect(add_user_window, SIGNAL(userSelected(User*)), this, SLOT(setUser(User*)));
}

/******************************************************/
void MainWindow::editUser()
{
	SpecifyUserWindow* edit_user_window = new SpecifyUserWindow();
	edit_user_window->setUser(_current_user);
	connect(edit_user_window, SIGNAL(userSelected(User*)), this, SLOT(setUser(User*)));
}

/******************************************************/
void MainWindow::setUser(User* user)
{
	_current_user = user;
	_ride_selector->setUser(_current_user);
	
	_edit_act->setEnabled(true);
	_totals_act->setEnabled(true);
	user->writeToFile(QString(".") + USER_DIRECTORY + user->name() + QString(".rider"));
}

/******************************************************/
void MainWindow::setRide(DataLog* data_log)
{
	// Plot 2d curves (important to be called first since it is responsible for signal filtering)
	_plot_window->displayRide(data_log, _current_user);

	// Overlay route in Google maps
	_google_map->displayRide(data_log);

	// Statistical viewer
	_stats_view->displayRide(data_log, _current_user);
}

/******************************************************/
void MainWindow::setLap(int lap_index)
{
	// Zoom plots to lap (this automatically propogates to map and stats)
	_plot_window->displayLap(lap_index);
}

/******************************************************/
 void MainWindow::about()
 {
	 // Create and display about window
	QPixmap about_image("resources/about_screen.png"); 
	AboutWindow* about = new AboutWindow(about_image);
	about->setMessageRect(QRect::QRect(10, 60, 250, 50), Qt::AlignLeft); // setting the message position
	 
	QFont about_font;
	about_font.setFamily("Arial");
	about_font.setPixelSize(10);
	about_font.setBold(true);
	 
	about->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::SplashScreen);
	about->setFont(about_font);
	about->showVersionInfo(tr(VERSION_INFO));
	about->show();
 }

/******************************************************/
void MainWindow::totals()
{
	_totals_window = new TotalsWindow(_current_user);
	_totals_window->show();
}

/******************************************************/
void MainWindow::createActions()
{
	_set_act = new QAction(tr("Select..."), this);
	connect(_set_act, SIGNAL(triggered()), this, SLOT(promptForUser()));

	_add_act = new QAction(tr("Add..."), this);
	connect(_add_act, SIGNAL(triggered()), this, SLOT(addUser()));

	_edit_act = new QAction(tr("Edit..."), this);
	_edit_act->setEnabled(false);
	connect(_edit_act, SIGNAL(triggered()), this, SLOT(editUser()));

	_totals_act = new QAction(tr("Totals"), this);
	_totals_act->setEnabled(false);
	connect(_totals_act, SIGNAL(triggered()), this, SLOT(totals()));

	_exit_act = new QAction(tr("Exit"), this);
	connect(_exit_act, SIGNAL(triggered()), this, SLOT(close()));

	_about_act = new QAction(tr("About"), this);
	connect(_about_act, SIGNAL(triggered()), this, SLOT(about()));
}

/******************************************************/
void MainWindow::createMenus()
{
	_file_menu = new QMenu(tr("&Rider"), this);
	_file_menu->addAction(_set_act);
	_file_menu->addAction(_add_act);
	_file_menu->addAction(_edit_act);
	_file_menu->addSeparator();
	_file_menu->addAction(_exit_act);

	_view_menu = new QMenu(tr("&View"), this);
	_view_menu->addAction(_totals_act);

	_help_menu = new QMenu(tr("&Help"), this);
	_help_menu->addAction(_about_act);

	menuBar()->addMenu(_file_menu);
	menuBar()->addMenu(_view_menu);
	menuBar()->addMenu(_help_menu);
}
