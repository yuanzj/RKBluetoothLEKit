//
//  UEUDID.h
//  RokyinfoBLEDemo
//
//  Created by Yuan ZhiJian on 2016/11/29.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import "BaseParameter.h"
#import "UEVersionResponse.h"


@interface UEUDID : BaseParameter

@property(nonatomic,assign)UEType type;

@property(nonatomic,copy)NSString *UDID;

@end
