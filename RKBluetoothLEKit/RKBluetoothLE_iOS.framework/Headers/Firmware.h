//
//  Firmware.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/3.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Firmware : NSObject

@property (nonatomic,copy  ) NSString *ueSn;

@property (nonatomic,copy  ) NSString *version;

@property (nonatomic,assign) long     fileSize;

@property (nonatomic,assign) Byte     singlePackageSize;

@property (nonatomic,assign) short    singleFrameSize;

@property (nonatomic,assign) BOOL     isForceUpgradeMode;

@property (nonatomic,copy  ) NSData   *data;

@property (nonatomic,copy  ) NSString *md5;

@end
