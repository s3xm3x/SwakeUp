/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.8 at Sun May 07 21:21:14 2017. */

#include "swakeup.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t Weather_fields[7] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, Weather, weatherType, weatherType, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, Weather, temperature, weatherType, 0),
    PB_FIELD(  3, STRING  , SINGULAR, STATIC  , OTHER, Weather, unit, temperature, 0),
    PB_FIELD(  4, STRING  , SINGULAR, STATIC  , OTHER, Weather, city, unit, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, Weather, sunrise, city, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, Weather, sunset, sunrise, 0),
    PB_LAST_FIELD
};

const pb_field_t Location_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, STATIC  , FIRST, Location, country, country, 0),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, Location, city, country, 0),
    PB_LAST_FIELD
};

const pb_field_t DateAndTime_fields[7] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, DateAndTime, year, year, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, DateAndTime, month, year, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, DateAndTime, day, month, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, DateAndTime, hour, day, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, DateAndTime, minute, hour, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, DateAndTime, second, minute, 0),
    PB_LAST_FIELD
};

const pb_field_t MsgFrame_fields[6] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, MsgFrame, typ, typ, 0),
    PB_FIELD(  2, BOOL    , SINGULAR, STATIC  , OTHER, MsgFrame, request, typ, 0),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, MsgFrame, location, request, &Location_fields),
    PB_ONEOF_FIELD(pl,  16, MESSAGE , ONEOF, STATIC  , OTHER, MsgFrame, dateAndTime, location, &DateAndTime_fields),
    PB_ONEOF_FIELD(pl,  17, MESSAGE , ONEOF, STATIC  , UNION, MsgFrame, weather, location, &Weather_fields),
    PB_LAST_FIELD
};




/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(MsgFrame, pl.dateAndTime) < 65536 && pb_membersize(MsgFrame, pl.weather) < 65536 && pb_membersize(MsgFrame, location) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_Weather_Location_DateAndTime_MsgFrame)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(MsgFrame, pl.dateAndTime) < 256 && pb_membersize(MsgFrame, pl.weather) < 256 && pb_membersize(MsgFrame, location) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_Weather_Location_DateAndTime_MsgFrame)
#endif


/* @@protoc_insertion_point(eof) */
