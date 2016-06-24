//
//  UpgradeProgress.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/23.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Firmware.h"
#import "RKPackage.h"
#import "RequestUpgradeResponse.h"
#import "RequestPackageResponse.h"
#import "FinishPackageResponse.h"
#import "MD5CheckResponse.h"

typedef NS_ENUM(NSInteger, UpgradeProgressStep) {

    UpgradeRequestUpgrade = 0,
    UpgradeRequestPackage = 1,
    UpgradeSendFrame      = 2,
    UpgradeFinishPackage  = 3,
    UpgradeCheckMD5       = 4,
    UpgradeReboot         = 5,

};

typedef NS_ENUM(NSInteger, UpgradeRunningStatus) {

    UpgradeDefault        = -1,
    UpgradeRunning        = 0,
    UpgradeInterrupt      = 1,
    UpgradeError          = 2,
    UpgradeDone           = 3,
    UpgradeRebooting      = 4,

};

@interface UpgradeProgress : NSObject

//当前运行状态
@property (nonatomic,assign) UpgradeRunningStatus   runningStatus;
//当前步骤
@property (nonatomic,assign) UpgradeProgressStep    step;
//剩余时间
@property (nonatomic,assign) long                   remainingTime;
//已完成百分比
@property (nonatomic,assign) float                  percentage;
//重启倒计时
@property (nonatomic,assign) int                    rebootCountdown;

@property (nonatomic,strong) Firmware               *curFirmware;

@property (nonatomic,strong) NSError                *error;

@property (nonatomic,strong) RequestUpgradeResponse *curRequestUpgradeResponse;

@property (nonatomic,strong) RequestPackageResponse *curRequestPackageResponse;

@property (nonatomic,strong) FinishPackageResponse  *curFinishPackageResponse;

@property (nonatomic,strong) MD5CheckResponse       *curMD5CheckResponse;

@end
