//
//  BleLog.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/13.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BleLog : NSObject

+(BOOL)getLogEnable;

+(void)setLogEnable:(BOOL)enable;

+(void)addMarker:(NSString*)mark;

@end
