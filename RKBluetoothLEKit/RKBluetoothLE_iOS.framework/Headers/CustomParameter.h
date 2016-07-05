//
//  CustomParameter.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/6/23.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseParameter.h"

@interface CustomParameter : BaseParameter

//震动告警方式
//1
//0~3
//0：声光同时，1：灯光告警，2：声音告警，3：铁喇叭+灯光告警，缺省：0
//自动锁车时间
//1
//
//单位：分钟，缺省为2分钟
//自动驻车时间
//1
//
//单位：分钟，缺省为2分钟
//喇叭音量大小
//1
//0-2
//0,1,2分别表示低，中，高三档音量，缺省：1
//三色灯支持
//3
//Array[3]
//三基色值
//缺省为：255,255,255
//延时关闭大灯
//1
//0-30
//延迟关闭大灯（单位：秒），缺省0，最大值不超过30
//定时开启时间
//4
//
//起始HHMM—结束HHMM，缺省秒00

//震动告警方式 0：声光同时，1：灯光告警，2：声音告警，3：铁喇叭+灯光告警，缺省：1
@property (assign, nonatomic) Byte alarmType;

//自动锁车时间 单位：分钟，缺省为2分钟
@property (assign, nonatomic) Byte autoSafety;

//自动驻车时间
@property (assign, nonatomic) Byte autoHold;

//喇叭音量大小 0,1,2分别表示低，中，高三档音量
@property (assign, nonatomic) Byte hornVolume;

//三色灯支持 三基色值 缺省为0[ R , G , B] 0x000000;
@property (assign, nonatomic) int  colorfulLight;

//延时关闭大灯 延迟关闭大灯（单位：秒），缺省0，最大值不超过30
@property (assign, nonatomic) Byte autoCloseLight;

//定时开启时间
@property (assign, nonatomic) Byte onTimeOpenLightStartHH;

@property (assign, nonatomic) Byte onTimeOpenLightStartMM;

@property (assign, nonatomic) Byte onTimeOpenLightEndHH;

@property (assign, nonatomic) Byte onTimeOpenLightEndMM;

//档位信息
//两档：0：常规，1：动力档
@property (assign, nonatomic) Byte gears;


+(CustomParameter*)createDefault;

@end
