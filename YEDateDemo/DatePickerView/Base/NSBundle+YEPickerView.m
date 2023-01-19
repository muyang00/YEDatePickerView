//
//  NSBundle+YEPickerView.m
//  YEPickerView
//
//  Created by yongen on 19/10/18.
//  Copyright © 2017年 yongen. All rights reserved.
//

#import "NSBundle+YEPickerView.h"
#import "YEPickerBaseView.h"

YESYNTH_DUMMY_CLASS(NSBundle_YEPickerView)

@implementation NSBundle (YEPickerView)

#pragma mark - 获取 YEPickerView.bundle
+ (instancetype)ye_pickerBundle {
    static NSBundle *pickerBundle = nil;
    if (!pickerBundle) {
        /*
            先拿到最外面的 bundle。
            对 framework 链接方式来说就是 framework 的 bundle 根目录，
            对静态库链接方式来说就是 target client 的 main bundle，
            然后再去找下面名为 YEPickerView 的 bundle 对象。
         */
        NSBundle *bundle = [NSBundle bundleForClass:[YEPickerBaseView class]];
        NSURL *url = [bundle URLForResource:@"YEPickerView" withExtension:@"bundle"];
        pickerBundle = [NSBundle bundleWithURL:url];
    }
    return pickerBundle;
}

#pragma mark - 获取国际化后的文本
+ (NSString *)ye_localizedStringForKey:(NSString *)key language:(NSString *)language {
    return [self ye_localizedStringForKey:key value:nil language:language];
}

+ (NSString *)ye_localizedStringForKey:(NSString *)key value:(NSString *)value language:(NSString *)language {
    static NSBundle *bundle = nil;
    if (!bundle) {
        // 如果没有手动设置语言，将随系统的语言自动改变
        if (!language) {
            // 系统首选语言
            language = [NSLocale preferredLanguages].firstObject;
        }
        
        if ([language hasPrefix:@"en"]) {
            language = @"en";
        } else if ([language hasPrefix:@"zh"]) {
            if ([language rangeOfString:@"Hans"].location != NSNotFound) {
                language = @"zh-Hans"; // 简体中文
            } else { // zh-Hant、zh-HK、zh-TW
                language = @"zh-Hant"; // 繁體中文
            }
        } else {
            language = @"en";
        }
        
        // 从 YEPickerView.bundle 中查找资源
        bundle = [NSBundle bundleWithPath:[[self ye_pickerBundle] pathForResource:language ofType:@"lproj"]];
    }
    value = [bundle localizedStringForKey:key value:value table:nil];
    
    return [[NSBundle mainBundle] localizedStringForKey:key value:value table:nil];
}

@end
