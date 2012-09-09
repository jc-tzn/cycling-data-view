#include "dateselectorwidget.h"

#include <QGridLayout.h>
#include <QSlider.h>
#include <QLabel.h>
#include <QCheckBox.h>

#include <cassert>
#include <sstream>
#include <iostream>

/******************************************************/
DateSelectorWidget::DateSelectorWidget(
	QDate& start_date, QDate& end_date):
QWidget(),
_start_date(start_date),
_end_date(end_date)
{
	assert(end_date.daysTo(start_date) < 0);

	// Create GUI widgets
	_all_dates_cb = new QCheckBox("All dates");
	_all_dates_cb->setChecked(true);

	const int n_days = start_date.daysTo(end_date);

	_min_date_slider = new QSlider(Qt::Horizontal);
	_min_date_slider->setRange(0,n_days);
	_min_date_slider->setValue(0);
	
	_max_date_slider = new QSlider(Qt::Horizontal);
	_max_date_slider->setRange(0,n_days);
	_max_date_slider->setValue(n_days);
	
	_min_date_label = new QLabel("Start date: ");
	_max_date_label = new QLabel("End date: ");
	
	// Connacet all signals/slots
	connect(_all_dates_cb, SIGNAL(stateChanged(int)), this, SLOT(setSlidersDisabled(int)));
	connect(_min_date_slider, SIGNAL(valueChanged(int)), this, SLOT(minSliderChanged(int)));
	connect(_max_date_slider, SIGNAL(valueChanged(int)), this, SLOT(maxSliderChanged(int)));
	connect(_max_date_slider, SIGNAL(sliderReleased()), this, SLOT(userChangedDates()));
	connect(_min_date_slider, SIGNAL(sliderReleased()), this, SLOT(userChangedDates()));
	connect(_all_dates_cb, SIGNAL(stateChanged(int)), this, SLOT(userChangedDates()));

	// Layout the GUI
	updateLabels();
	setSlidersDisabled(true);

	QGridLayout* gridlayout1 = new QGridLayout(this);
	gridlayout1->addWidget(_all_dates_cb, 0, 0);
	gridlayout1->addWidget(_min_date_slider, 0, 1);
	gridlayout1->addWidget(_min_date_label, 0, 2);
	gridlayout1->addWidget(_max_date_slider, 1, 1);
	gridlayout1->addWidget(_max_date_label, 1, 2);

}

/******************************************************/
DateSelectorWidget::~DateSelectorWidget()
{

}

/******************************************************/
void DateSelectorWidget::updateLabels()
{
	QDate current_min = _start_date.addDays(_min_date_slider->value());
	QDate current_max = _start_date.addDays(_max_date_slider->value());

	_min_date_label->setText(tr("Start date: ") + current_min.toString(tr("dd.MM.yyyy")));
	_max_date_label->setText(tr("End date: ") + current_max.toString(tr("dd.MM.yyyy")));
}

/******************************************************/
void DateSelectorWidget::setSlidersDisabled(int diabled)
{
	_min_date_slider->setDisabled(diabled);
	_max_date_slider->setDisabled(diabled);

	_min_date_label->setDisabled(diabled);
	_max_date_label->setDisabled(diabled);
}

/******************************************************/
void DateSelectorWidget::minSliderChanged(int day_number)
{
	QDate date = _start_date.addDays(day_number);
	_min_date_label->setText(tr("Start date: ") + date.toString(tr("dd.MM.yyyy")));

	// Handle overlap with max slider
	if (_min_date_slider->value() >= _max_date_slider->value())
		_max_date_slider->setValue(_min_date_slider->value() + 1);
}

/******************************************************/
void DateSelectorWidget::maxSliderChanged(int day_number)
{
	QDate date = _start_date.addDays(day_number);
	_max_date_label->setText(tr("End date: ") + date.toString(tr("dd.MM.yyyy")));

	// Handle overlap with min slider
	if (_max_date_slider->value() <= _min_date_slider->value())
		_min_date_slider->setValue(_max_date_slider->value() - 1);
}

/******************************************************/
void DateSelectorWidget::userChangedDates()
{
	emit datesChanged();
}

/******************************************************/
QDate& DateSelectorWidget::minDate()
{
	if (_all_dates_cb->isChecked())
		return _start_date;
	else
		return _start_date.addDays(_min_date_slider->value());
}

/******************************************************/
QDate& DateSelectorWidget::maxDate()
{
	if (_all_dates_cb->isChecked())
		return _end_date;
	else
		return _start_date.addDays(_max_date_slider->value());
}