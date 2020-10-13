#ifndef __FLASH_H__
#define __FLASH_H__
#include "HC89F303.h"

#define FLASH_CHECK_ADDRESS   0X3C00 //1024*14 = 0X3800   
#define FLASH_DATA_ADDRESS	FLASH_CHECK_ADDRESS + 4

#define Correct_Value  2
#define first_heat_power  50  // 58~60W
#define second_heat_power 50  // 31 -> 48~50W

typedef enum TIMER_TYPE
{
	TIMER_ON	= 0X00,
	TIMER_0_5H 	= 0X01,
	TIMER_1H	= 0X02,
	TIMER_2H	= 0X03,
	TIMER_4H	= 0X04,
	TIMER_8H	= 0X05
};

typedef enum GAP_TYPE
{
	GAP_WARM	= 0X00,
	GAP_1 	= 0X01,
	GAP_2	= 0X02,
	GAP_3	= 0X03,
	GAP_4	= 0X04,
	GAP_5	= 0X05,
	GAP_6	= 0X06,
	GAP_7	= 0X07,
	GAP_8	= 0X08,
	GAP_9	= 0X09,

};

typedef enum GAP_TEMP
{
	GAP_WARM_temp	= 30,
	GAP_1_temp 	= 40,
	GAP_2_temp	= 43,
	GAP_3_temp	= 47,
	GAP_4_temp	= 54,
	GAP_5_temp	= 60,
	GAP_6_temp	= 65,
	GAP_7_temp	= 70,
	GAP_8_temp	= 70,
	GAP_9_temp	= 77,
	One_Heat_Temp = 77,
};
	typedef enum corrected_value
	{
		corrected_value_warm_temp	= 1,
		corrected_value_GAP_1_temp	= 1,
		corrected_value_GAP_2_temp	= 1,
		corrected_value_GAP_3_temp	= 1,
		corrected_value_GAP_4_temp	= 3,
		corrected_value_GAP_5_temp	= 5,
		corrected_value_GAP_6_temp	= 5,
		corrected_value_GAP_7_temp	= 5,
		corrected_value_GAP_8_temp	= 8,
		corrected_value_GAP_9_temp	= 8,
	
	};

	typedef enum corrected_time
		{
			
			corrected_time_warm_temp	= 30*1,
			corrected_time_GAP_1_temp	= 30*5,
			corrected_time_GAP_2_temp	= 60*4,
			corrected_time_GAP_3_temp	= 60*5,
			corrected_time_GAP_4_temp	= 60*6,
			corrected_time_GAP_5_temp	= 60*7,
			corrected_time_GAP_6_temp	= 60*11,
			corrected_time_GAP_7_temp	= 60*17,
			corrected_time_GAP_8_temp	= 60*27,
			corrected_time_GAP_9_temp	= 60*27,
		
		};

typedef enum DEVICE_STATE
{
	ON	= 0X00,
	OFF = 0X01
};


typedef struct _flash_info_t
{
	u8 gap;
	u8 timer;
	u8 correct_value;
	u8 correct_sign;
	u8 correct_std;
} flash_info_t;

extern flash_info_t flash_info;


void flash_init ( void );
void flah_save_data ( void );

u8 get_device_state ( void );
void set_device_state ( u8 state );


#endif

