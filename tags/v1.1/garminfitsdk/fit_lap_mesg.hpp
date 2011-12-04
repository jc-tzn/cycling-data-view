////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2008 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 1.50Release
// Tag = $Name: AKW1_500 $
////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_LAP_MESG_HPP)
#define FIT_LAP_MESG_HPP

#include "fit_mesg.hpp"
#include "fit_mesg_with_event.hpp"

namespace fit
{

class LapMesg : public Mesg, public MesgWithEvent
{
   public:
      LapMesg(void) : Mesg(Profile::MESG_LAP)
      {
      }

      LapMesg(const Mesg &mesg) : Mesg(mesg)
      {
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns message_index field
      ///////////////////////////////////////////////////////////////////////
      FIT_MESSAGE_INDEX GetMessageIndex(void) const
      {
         return GetFieldUINT16Value(254, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set message_index field
      ///////////////////////////////////////////////////////////////////////
      void SetMessageIndex(FIT_MESSAGE_INDEX messageIndex)
      {
         SetFieldUINT16Value(254, messageIndex, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns timestamp field
      // Units: s
      // Comment: Lap end time.
      ///////////////////////////////////////////////////////////////////////
      FIT_DATE_TIME GetTimestamp(void) const
      {
         return GetFieldUINT32Value(253, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set timestamp field
      // Units: s
      // Comment: Lap end time.
      ///////////////////////////////////////////////////////////////////////
      void SetTimestamp(FIT_DATE_TIME timestamp)
      {
         SetFieldUINT32Value(253, timestamp, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns event field
      ///////////////////////////////////////////////////////////////////////
      FIT_EVENT GetEvent(void) const
      {
         return GetFieldENUMValue(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set event field
      ///////////////////////////////////////////////////////////////////////
      void SetEvent(FIT_EVENT event)
      {
         SetFieldENUMValue(0, event, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns event_type field
      ///////////////////////////////////////////////////////////////////////
      FIT_EVENT_TYPE GetEventType(void) const
      {
         return GetFieldENUMValue(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set event_type field
      ///////////////////////////////////////////////////////////////////////
      void SetEventType(FIT_EVENT_TYPE eventType)
      {
         SetFieldENUMValue(1, eventType, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns start_time field
      ///////////////////////////////////////////////////////////////////////
      FIT_DATE_TIME GetStartTime(void) const
      {
         return GetFieldUINT32Value(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set start_time field
      ///////////////////////////////////////////////////////////////////////
      void SetStartTime(FIT_DATE_TIME startTime)
      {
         SetFieldUINT32Value(2, startTime, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns start_position_lat field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT32 GetStartPositionLat(void) const
      {
         return GetFieldSINT32Value(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set start_position_lat field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      void SetStartPositionLat(FIT_SINT32 startPositionLat)
      {
         SetFieldSINT32Value(3, startPositionLat, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns start_position_long field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT32 GetStartPositionLong(void) const
      {
         return GetFieldSINT32Value(4, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set start_position_long field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      void SetStartPositionLong(FIT_SINT32 startPositionLong)
      {
         SetFieldSINT32Value(4, startPositionLong, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns end_position_lat field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT32 GetEndPositionLat(void) const
      {
         return GetFieldSINT32Value(5, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set end_position_lat field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      void SetEndPositionLat(FIT_SINT32 endPositionLat)
      {
         SetFieldSINT32Value(5, endPositionLat, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns end_position_long field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT32 GetEndPositionLong(void) const
      {
         return GetFieldSINT32Value(6, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set end_position_long field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      void SetEndPositionLong(FIT_SINT32 endPositionLong)
      {
         SetFieldSINT32Value(6, endPositionLong, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_elapsed_time field
      // Units: s
      // Comment: Time (includes pauses)
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetTotalElapsedTime(void) const
      {
         return GetFieldFLOAT32Value(7, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_elapsed_time field
      // Units: s
      // Comment: Time (includes pauses)
      ///////////////////////////////////////////////////////////////////////
      void SetTotalElapsedTime(FIT_FLOAT32 totalElapsedTime)
      {
         SetFieldFLOAT32Value(7, totalElapsedTime, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_timer_time field
      // Units: s
      // Comment: Timer Time (excludes pauses)
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetTotalTimerTime(void) const
      {
         return GetFieldFLOAT32Value(8, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_timer_time field
      // Units: s
      // Comment: Timer Time (excludes pauses)
      ///////////////////////////////////////////////////////////////////////
      void SetTotalTimerTime(FIT_FLOAT32 totalTimerTime)
      {
         SetFieldFLOAT32Value(8, totalTimerTime, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_distance field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetTotalDistance(void) const
      {
         return GetFieldFLOAT32Value(9, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_distance field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetTotalDistance(FIT_FLOAT32 totalDistance)
      {
         SetFieldFLOAT32Value(9, totalDistance, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_cycles field
      // Units: cycles
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetTotalCycles(void) const
      {
         return GetFieldUINT32Value(10, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_cycles field
      // Units: cycles
      ///////////////////////////////////////////////////////////////////////
      void SetTotalCycles(FIT_UINT32 totalCycles)
      {
         SetFieldUINT32Value(10, totalCycles, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_strides field
      // Units: strides
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetTotalStrides(void) const
      {
         return GetFieldUINT32Value(10, 0, (FIT_UINT16) Profile::LAP_MESG_TOTAL_CYCLES_FIELD_TOTAL_STRIDES);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_strides field
      // Units: strides
      ///////////////////////////////////////////////////////////////////////
      void SetTotalStrides(FIT_UINT32 totalStrides)
      {
         SetFieldUINT32Value(10, totalStrides, 0, (FIT_UINT16) Profile::LAP_MESG_TOTAL_CYCLES_FIELD_TOTAL_STRIDES);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_calories field
      // Units: kcal
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetTotalCalories(void) const
      {
         return GetFieldUINT16Value(11, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_calories field
      // Units: kcal
      ///////////////////////////////////////////////////////////////////////
      void SetTotalCalories(FIT_UINT16 totalCalories)
      {
         SetFieldUINT16Value(11, totalCalories, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_fat_calories field
      // Units: kcal
      // Comment: If New Leaf
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetTotalFatCalories(void) const
      {
         return GetFieldUINT16Value(12, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_fat_calories field
      // Units: kcal
      // Comment: If New Leaf
      ///////////////////////////////////////////////////////////////////////
      void SetTotalFatCalories(FIT_UINT16 totalFatCalories)
      {
         SetFieldUINT16Value(12, totalFatCalories, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns avg_speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetAvgSpeed(void) const
      {
         return GetFieldFLOAT32Value(13, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set avg_speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      void SetAvgSpeed(FIT_FLOAT32 avgSpeed)
      {
         SetFieldFLOAT32Value(13, avgSpeed, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetMaxSpeed(void) const
      {
         return GetFieldFLOAT32Value(14, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      void SetMaxSpeed(FIT_FLOAT32 maxSpeed)
      {
         SetFieldFLOAT32Value(14, maxSpeed, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns avg_heart_rate field
      // Units: bpm
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetAvgHeartRate(void) const
      {
         return GetFieldUINT8Value(15, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set avg_heart_rate field
      // Units: bpm
      ///////////////////////////////////////////////////////////////////////
      void SetAvgHeartRate(FIT_UINT8 avgHeartRate)
      {
         SetFieldUINT8Value(15, avgHeartRate, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_heart_rate field
      // Units: bpm
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetMaxHeartRate(void) const
      {
         return GetFieldUINT8Value(16, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_heart_rate field
      // Units: bpm
      ///////////////////////////////////////////////////////////////////////
      void SetMaxHeartRate(FIT_UINT8 maxHeartRate)
      {
         SetFieldUINT8Value(16, maxHeartRate, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns avg_cadence field
      // Units: rpm
      // Comment: total_cycles / total_timer_time if non_zero_avg_cadence otherwise total_cycles / total_elapsed_time
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetAvgCadence(void) const
      {
         return GetFieldUINT8Value(17, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set avg_cadence field
      // Units: rpm
      // Comment: total_cycles / total_timer_time if non_zero_avg_cadence otherwise total_cycles / total_elapsed_time
      ///////////////////////////////////////////////////////////////////////
      void SetAvgCadence(FIT_UINT8 avgCadence)
      {
         SetFieldUINT8Value(17, avgCadence, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns avg_running_cadence field
      // Units: strides/min
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetAvgRunningCadence(void) const
      {
         return GetFieldUINT8Value(17, 0, (FIT_UINT16) Profile::LAP_MESG_AVG_CADENCE_FIELD_AVG_RUNNING_CADENCE);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set avg_running_cadence field
      // Units: strides/min
      ///////////////////////////////////////////////////////////////////////
      void SetAvgRunningCadence(FIT_UINT8 avgRunningCadence)
      {
         SetFieldUINT8Value(17, avgRunningCadence, 0, (FIT_UINT16) Profile::LAP_MESG_AVG_CADENCE_FIELD_AVG_RUNNING_CADENCE);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_cadence field
      // Units: rpm
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetMaxCadence(void) const
      {
         return GetFieldUINT8Value(18, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_cadence field
      // Units: rpm
      ///////////////////////////////////////////////////////////////////////
      void SetMaxCadence(FIT_UINT8 maxCadence)
      {
         SetFieldUINT8Value(18, maxCadence, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_running_cadence field
      // Units: strides/min
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetMaxRunningCadence(void) const
      {
         return GetFieldUINT8Value(18, 0, (FIT_UINT16) Profile::LAP_MESG_MAX_CADENCE_FIELD_MAX_RUNNING_CADENCE);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_running_cadence field
      // Units: strides/min
      ///////////////////////////////////////////////////////////////////////
      void SetMaxRunningCadence(FIT_UINT8 maxRunningCadence)
      {
         SetFieldUINT8Value(18, maxRunningCadence, 0, (FIT_UINT16) Profile::LAP_MESG_MAX_CADENCE_FIELD_MAX_RUNNING_CADENCE);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns avg_power field
      // Units: watts
      // Comment: total_power / total_timer_time if non_zero_avg_power otherwise total_power / total_elapsed_time
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetAvgPower(void) const
      {
         return GetFieldUINT16Value(19, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set avg_power field
      // Units: watts
      // Comment: total_power / total_timer_time if non_zero_avg_power otherwise total_power / total_elapsed_time
      ///////////////////////////////////////////////////////////////////////
      void SetAvgPower(FIT_UINT16 avgPower)
      {
         SetFieldUINT16Value(19, avgPower, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetMaxPower(void) const
      {
         return GetFieldUINT16Value(20, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      void SetMaxPower(FIT_UINT16 maxPower)
      {
         SetFieldUINT16Value(20, maxPower, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_ascent field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetTotalAscent(void) const
      {
         return GetFieldUINT16Value(21, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_ascent field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetTotalAscent(FIT_UINT16 totalAscent)
      {
         SetFieldUINT16Value(21, totalAscent, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_descent field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetTotalDescent(void) const
      {
         return GetFieldUINT16Value(22, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_descent field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetTotalDescent(FIT_UINT16 totalDescent)
      {
         SetFieldUINT16Value(22, totalDescent, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns intensity field
      ///////////////////////////////////////////////////////////////////////
      FIT_INTENSITY GetIntensity(void) const
      {
         return GetFieldENUMValue(23, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set intensity field
      ///////////////////////////////////////////////////////////////////////
      void SetIntensity(FIT_INTENSITY intensity)
      {
         SetFieldENUMValue(23, intensity, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns lap_trigger field
      ///////////////////////////////////////////////////////////////////////
      FIT_LAP_TRIGGER GetLapTrigger(void) const
      {
         return GetFieldENUMValue(24, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set lap_trigger field
      ///////////////////////////////////////////////////////////////////////
      void SetLapTrigger(FIT_LAP_TRIGGER lapTrigger)
      {
         SetFieldENUMValue(24, lapTrigger, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns sport field
      ///////////////////////////////////////////////////////////////////////
      FIT_SPORT GetSport(void) const
      {
         return GetFieldENUMValue(25, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set sport field
      ///////////////////////////////////////////////////////////////////////
      void SetSport(FIT_SPORT sport)
      {
         SetFieldENUMValue(25, sport, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns event_group field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetEventGroup(void) const
      {
         return GetFieldUINT8Value(26, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set event_group field
      ///////////////////////////////////////////////////////////////////////
      void SetEventGroup(FIT_UINT8 eventGroup)
      {
         SetFieldUINT8Value(26, eventGroup, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns normalized_power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetNormalizedPower(void) const
      {
         return GetFieldUINT16Value(33, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set normalized_power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      void SetNormalizedPower(FIT_UINT16 normalizedPower)
      {
         SetFieldUINT16Value(33, normalizedPower, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns left_right_balance field
      ///////////////////////////////////////////////////////////////////////
      FIT_LEFT_RIGHT_BALANCE_100 GetLeftRightBalance(void) const
      {
         return GetFieldUINT16Value(34, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set left_right_balance field
      ///////////////////////////////////////////////////////////////////////
      void SetLeftRightBalance(FIT_LEFT_RIGHT_BALANCE_100 leftRightBalance)
      {
         SetFieldUINT16Value(34, leftRightBalance, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns checksum field
      ///////////////////////////////////////////////////////////////////////
      FIT_CHECKSUM GetChecksum(void) const
      {
         return GetFieldUINT8Value(252, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set checksum field
      ///////////////////////////////////////////////////////////////////////
      void SetChecksum(FIT_CHECKSUM checksum)
      {
         SetFieldUINT8Value(252, checksum, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

};

} // namespace fit

#endif // !defined(FIT_LAP_MESG_HPP)
