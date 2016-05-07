//
//  UpgradeManager.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/4.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>
#import "RK410APIService.h"
#import "Firmware.h"


@interface UpgradeManager : NSObject

-(RACSignal*)upgradeTarget:(NSString*)target  withAPIService:(RK410APIService*) mRK410APIService andFirmware:(Firmware*)mFirmware;

@end
