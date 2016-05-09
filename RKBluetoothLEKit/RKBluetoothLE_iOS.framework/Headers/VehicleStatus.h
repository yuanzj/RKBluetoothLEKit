//
//  VehicleStatus.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/5.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RkFieldConverter.h"

typedef NS_ENUM(NSInteger, LOCK_STATUS) {

    UNKNOW   = 0,
    LOCKED   = 1,
    UNLOCKED = 2,

};

@interface VehicleStatus : NSObject<RkFieldConverter>

//电压
@property (assign, nonatomic) float voltage;
//温度
@property (assign, nonatomic) float temperature;
//电流
@property (assign, nonatomic) float electricCurrent;
//速度
@property (assign, nonatomic) float speed;
//总里程
@property (assign, nonatomic) float totalODO;
//锁车状态
@property (assign, nonatomic) int   lockStatus;
//左转向指示
@property (assign, nonatomic) BOOL  leftSignal;
//右转向指示
@property (assign, nonatomic) BOOL  rightSignal;
//尾灯指示
@property (assign, nonatomic) BOOL  rearlightsSignal;
//背景灯指示
@property (assign, nonatomic) BOOL  backlightSignal;
//大灯远光
@property (assign, nonatomic) BOOL  highBeam;
//大灯近光
@property (assign, nonatomic) BOOL  lowBean;
//喇叭
@property (assign, nonatomic) BOOL  horn;
//刹车指示
@property (assign, nonatomic) BOOL  brakeSignal;
//是否有故障 YES 有故障 :  NO: 没有故障
@property (assign, nonatomic) BOOL  faultFlag;
//电量百分比
@property (assign, nonatomic) int   electricPercent;
//剩余里程
@property (assign, nonatomic) int   remainderRange;

@end
