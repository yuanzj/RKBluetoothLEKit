//
//  BaseUpgradeResponse.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/12.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RkFieldConverter.h"

@interface BaseUpgradeResponse : NSObject<RkFieldConverter>

//命令码
@property (assign, nonatomic) Byte command;

//结果
@property (assign, nonatomic) Byte result;

-(BOOL)isHit:(NSData*)data;

-(int)getCommand;

@end
