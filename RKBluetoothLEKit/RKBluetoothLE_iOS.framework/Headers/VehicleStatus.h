//
//  VehicleStatus.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/5.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RkFieldConverter.h"

typedef NS_ENUM(NSInteger, STATUS) {

    STATUS_FORTIFICATION = 0,
    STATUS_DISARMING     = 1,
    STATUS_P             = 2,
    STATUS_D             = 3,
    STATUS_D_Motionless  = 4,
    
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
//锁车状态 车状态：0：设防，1：撤防不上电，2：驻车，3 ：行车
@property (assign, nonatomic) int   status;
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
//P档状态
@property (assign, nonatomic) BOOL  P;
//钥匙开关状态
@property (assign, nonatomic) BOOL  KSI;
//是否有故障 YES 有故障 :  NO: 没有故障
@property (assign, nonatomic) BOOL  faultFlag;
//电量百分比
@property (assign, nonatomic) int   electricPercent;
//剩余里程
@property (assign, nonatomic) int   remainderRange;

@end
