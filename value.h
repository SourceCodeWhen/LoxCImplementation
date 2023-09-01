#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef enum {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
} ValueType;

typedef struct {
    ValueType type;
    union {
        bool boolean;
        double number;
    } as;
} Value;

#define IS_BOOL(Value)      ((Value).type == VAL_BOOL)
#define IS_NIL(Value)       ((Value).type == VAL_NIL)
#define IS_NUMBER(Value)    ((Value).type == VAL_NUMBER)

#define AS_BOOL(Value)      ((Value).as.boolean)
#define AS_NUMBER(Value)    ((Value).as.number)

#define BOOL_VAL(Value)     ((Value){VAL_BOOL, {.boolean = value}})
#define NIL_VAL             ((Value){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(Value)   ((Value){VAL_NUMBER, {.number = value}})

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif
