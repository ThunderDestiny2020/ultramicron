#ifndef __main_user_H
#define __main_user_H


#include "stm32l1xx.h"

typedef struct
{
  FunctionalState Need_batt_voltage_update;    // ���������� �������� ������ �� ���������� ���������
//  FunctionalState Need_geiger_voltage_update;  // ���������� �������� ������ �� �������� ���������� 
  FunctionalState Need_fon_update;             // ���������� �������� ������ �� �������� ���������� 
  FunctionalState Need_display_update;         // ���������� �������� ������ �� �������� ���������� 
  uint16_t Batt_update_time_counter;            // ������� �������� ��������� ���������� ���
//  uint8_t Calibration_update_time_counter;     // ������� �������� ��������� ���������� ���
  uint8_t pump_counter_update_time;
	uint16_t  doze_sec_count;                    // ��������� ������� ��� ������� ����
//  uint8_t second_pump_counter;
//  uint8_t pump_pulse_by_impulse_counter;
  
}DataUpdateDef;


typedef struct
{
  uint32_t Batt_voltage_raw;        // ���������� ���
  uint32_t Batt_voltage;            // ���������� ���
  uint32_t Power_voltage;           // ���������� ������� ��
//  uint32_t Geiger_voltage_raw;      // ���������� ��������
//  uint32_t Geiger_voltage;          // ���������� ��������
  uint32_t Calibration_bit_voltage; // ���� ������ ����
  uint32_t Procent_battery;         // ���� ������ ����
  uint32_t DAC_voltage_raw;         // ������� ������� ��� DAC
  
}ADCDataDef;

typedef struct
{
  uint32_t Alarm_level;                             // ������� ������
  uint32_t Sleep_time;                              // ����� �� ����� � ���
  uint32_t Led_Sleep_time;                          // ����� �� ����� � ���
  uint32_t contrast;                                 // �������� �������
//  uint32_t second_pump;                              // ���-�� ��������� �������� ������ �������
//  uint32_t Geiger_angle_of_counter_characteristics; // ���� ������� ������� �������������� � ������� ����� �������� �� �����
//  uint32_t Geiger_plato_begin;                      // ������ �����
//  uint32_t Geiger_plato;                            // ������ �����
//  uint32_t HV_ADC_Corr;                             // ������������� �� ��������
//  uint32_t pump_pulse_by_impulse;                   // ���-�� ��������� �������� �� ������ ������� �������
//  uint32_t pump_skvagennost;                        // ������������ �������
  uint32_t Sound_freq;				    // ������� ����� � ���
  uint32_t Geiger_voltage;
	uint32_t Pump_Energy;
  uint32_t Display_reverse;                  // ��������� �������
  uint32_t Sound;                            // ���� ���-����
  uint32_t Second_count;
  uint32_t LSI_freq;
	
}SettingsDef;


typedef struct
{
  uint32_t Alarm_beep_count;
  uint32_t Tick_beep_count;
  FunctionalState Alarm_active; 
  FunctionalState User_cancel; 
  
  
}AlarmDef;

typedef struct
{
  FunctionalState ADC_active;     // ������ �������� ���
  FunctionalState Pump_active;    // � ������ ������ ���� �������
  FunctionalState Sound_active;   // � ������ �������� ����
  FunctionalState Display_active; // ������� �������
	FunctionalState USB_active;     // ������� USB
  
  uint32_t sleep_time;  //
	uint32_t led_sleep_time;  //
  
}PowerDef;

static __IO uint8_t  timer_is_reload = 0;	// counts 1ms timeTicks
extern uint16_t key; // ������ ������� ������ [012]
extern uint32_t ix;
extern uint32_t ix_update;

//#define count_seconds 75 // 
extern uint16_t Detector_massive[120+1];

#define doze_length 144 // 
extern uint32_t Doze_massive[doze_length+1]; // 1 ������ = 10 �����, �� ���������� �����
extern uint32_t max_fon_massive[doze_length+1]; // 1 ������ = 10 �����, �� ���������� �����
extern uint16_t Doze_sec_count;
extern uint32_t Doze_count;
extern uint32_t Doze_hour_count;
extern uint32_t Max_fon;
extern uint8_t  main_menu_stat;
extern uint32_t menu_select;
extern FunctionalState enter_menu_item;
extern uint8_t screen;
extern uint8_t stat_screen_number;
extern uint16_t Detector_massive_pointer;
extern uint16_t pump_counter_avg_impulse_by_1sec[2];
extern uint32_t fon_level;
extern uint8_t  auto_speedup_factor;

extern uint32_t fullstop;
extern FunctionalState Sound_key_pressed;

extern uint8_t second_divide;

extern uint16_t current_pulse_count;

extern ADCDataDef    ADCData;
extern DataUpdateDef DataUpdate;
extern PowerDef      Power;
extern SettingsDef Settings;
extern AlarmDef Alarm;

extern uint8_t pump_count;

void sleep_mode(FunctionalState sleep);

#endif