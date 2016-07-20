//
//  VersionResponse.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/7/20.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseParameter.h"

#define VERSION_TYPE_ECU    0
#define VERSION_TYPE_E_ECU  1

@interface VersionResponse : BaseParameter

@property(nonatomic,assign)int type;

@property(nonatomic,copy)NSString *sVersion;

@property(nonatomic,copy)NSString *hVersion;

@end
