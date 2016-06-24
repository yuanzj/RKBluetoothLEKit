//
//  Instrument.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/6/24.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseParameter.h"

@interface Instrument : BaseParameter

//来电
@property (assign, nonatomic) Byte telephone;

//短信
@property (assign, nonatomic) Byte SMS;

@end
