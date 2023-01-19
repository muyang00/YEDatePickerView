//
//  NSDate+YEPickerView.h
//  YEPickerView
//
//  Created by yongen on 17/2/13.
//  Copyright © 2017年 yongen. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (YEPickerView)
/// 获取指定date的详细信息
@property (readonly) NSInteger ye_year;         // 年
@property (readonly) NSInteger ye_month;        // 月
@property (readonly) NSInteger ye_day;          // 日
@property (readonly) NSInteger ye_hour;         // 时
@property (readonly) NSInteger ye_minute;       // 分
@property (readonly) NSInteger ye_second;       // 秒
@property (readonly) NSInteger ye_weekday;      // 星期
@property (readonly) NSInteger ye_monthWeek;    // 月周
@property (readonly) NSInteger ye_yearWeek;     // 年周
@property (readonly) NSInteger ye_quarter;      // 季度

/** 获取中文星期字符串 */
@property (nullable, nonatomic, readonly, copy) NSString *ye_weekdayString;

/** 获取日历单例对象 */
+ (NSCalendar *)ye_calendar;


/// ---------------- 创建 date ----------------
/** 通过 NSDateComponents对象 来创建 NSDate对象（可以设置时区） */
+ (nullable NSDate *)ye_setDateFromComponents:(NSDateComponents *)components timeZone:(NSTimeZone *)timeZone;

/** yyyy */
+ (nullable NSDate *)ye_setYear:(NSInteger)year;

/** yyyy-MM */
+ (nullable NSDate *)ye_setYear:(NSInteger)year month:(NSInteger)month;

/** yyyy-MM-dd */
+ (nullable NSDate *)ye_setYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;

/** yyyy-MM-dd HH */
+ (nullable NSDate *)ye_setYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day hour:(NSInteger)hour;

/** yyyy-MM-dd HH:mm */
+ (nullable NSDate *)ye_setYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day hour:(NSInteger)hour minute:(NSInteger)minute;

/** yyyy-MM-dd HH:mm:ss */
+ (nullable NSDate *)ye_setYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day hour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second;

/** MM-dd HH:mm */
+ (nullable NSDate *)ye_setMonth:(NSInteger)month day:(NSInteger)day hour:(NSInteger)hour minute:(NSInteger)minute;

/** MM-dd */
+ (nullable NSDate *)ye_setMonth:(NSInteger)month day:(NSInteger)day;

/** HH:mm:ss */
+ (nullable NSDate *)ye_setHour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second;

/** HH:mm */
+ (nullable NSDate *)ye_setHour:(NSInteger)hour minute:(NSInteger)minute;

/** mm:ss */
+ (nullable NSDate *)ye_setMinute:(NSInteger)minute second:(NSInteger)second;

/** yyyy-MM-ww */
+ (nullable NSDate *)ye_setYear:(NSInteger)year month:(NSInteger)month weekOfMonth:(NSInteger)weekOfMont;

/** yyyy-ww */
+ (nullable NSDate *)ye_setYear:(NSInteger)year weekOfYear:(NSInteger)weekOfYear;

/** yyyy-qq */
+ (nullable NSDate *)ye_setYear:(NSInteger)year quarter:(NSInteger)quarter;


/** 获取某个月的天数（通过年月求每月天数）*/
+ (NSUInteger)ye_getDaysInYear:(NSInteger)year month:(NSInteger)month;

/** 获取某个月的周数（通过年月求该月周数）*/
+ (NSUInteger)ye_getWeeksOfMonthInYear:(NSInteger)year month:(NSInteger)month;

/** 获取某一年的周数（通过年求该年周数）*/
+ (NSUInteger)ye_getWeeksOfYearInYear:(NSInteger)year;

/** 获取某一年的季度数（通过年求该年季度数）*/
+ (NSUInteger)ye_getQuartersInYear:(NSInteger)year;

/**  获取 日期加上/减去某天数后的新日期 */
- (nullable NSDate *)ye_getNewDateToDays:(NSTimeInterval)days;

/**  获取 日期加上/减去某个月数后的新日期 */
- (nullable NSDate *)ye_getNewDateToMonths:(NSTimeInterval)months;

/** NSDate 转 NSString */
+ (nullable NSString *)ye_stringFromDate:(NSDate *)date dateFormat:(NSString *)dateFormat;
/** NSDate 转 NSString */
+ (nullable NSString *)ye_stringFromDate:(NSDate *)date
                     dateFormat:(NSString *)dateFormat
                       timeZone:(nullable NSTimeZone *)timeZone
                       language:(nullable NSString *)language;


/** NSString 转 NSDate */
+ (nullable NSDate *)ye_dateFromString:(NSString *)dateString dateFormat:(NSString *)dateFormat;
/** NSString 转 NSDate */
+ (nullable NSDate *)ye_dateFromString:(NSString *)dateString
                   dateFormat:(NSString *)dateFormat
                     timeZone:(nullable NSTimeZone *)timeZone
                     language:(nullable NSString *)language;


/** NSDate 转 NSString（已弃用） */
+ (nullable NSString *)ye_getDateString:(NSDate *)date format:(NSString *)format DEPRECATED_MSG_ATTRIBUTE("Use 'ye_stringFromDate:dateFormat:' instead");

/** NSString 转 NSDate（已弃用） */
+ (nullable NSDate *)ye_getDate:(NSString *)dateString format:(NSString *)format DEPRECATED_MSG_ATTRIBUTE("Use 'ye_dateFromString:dateFormat:' instead");


@end

NS_ASSUME_NONNULL_END
