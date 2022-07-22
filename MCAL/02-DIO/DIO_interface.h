#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum{

    PIN_A0=0,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
    PIN_A6,
    PIN_A7,

    PIN_B0,
    PIN_B1,
    PIN_B2,
    PIN_B3,
    PIN_B4,
    PIN_B5,
    PIN_B6,
    PIN_B7,

    PIN_C0,
    PIN_C1,
    PIN_C2,
    PIN_C3,
    PIN_C4,
    PIN_C5,
    PIN_C6,
    PIN_C7,

    PIN_D0,
    PIN_D1,
    PIN_D2,
    PIN_D3,
    PIN_D4,
    PIN_D5,
    PIN_D6,
    PIN_D7,

    PIN_E0,
    PIN_E1,
    PIN_E2,
    PIN_E3,
    PIN_E4,
    PIN_E5,
    PIN_E6,
    PIN_E7,

    PIN_F0,
    PIN_F1,
    PIN_F2,
    PIN_F3,
    PIN_F4,
    PIN_F5,
    PIN_F6,
    PIN_F7


}DIO_CHANNEL_TYPE;

typedef enum{

    DIO_LOW=0,
    DIO_HIGH=1

}DIO_LEVEL_TYPE;

typedef enum{

    OUT_PUT_CURRENT_STREGNTH_2MA=0,
    OUT_PUT_CURRENT_STREGNTH_4MA,
    OUT_PUT_CURRENT_STREGNTH_8MA

}PIN_OUTPUT_CURRENT;

typedef enum{

    GPIO_INPUT=0,
    GPIO_OUTPUT

}PIN_DIRECTION_TYPE;

typedef enum{

    OPEN_DRAIN=0,
    PULL_UP,
    PULL_DOWN,
    SLEW_RATE,
    NOT_USED

}PIN_INTERNAL_ATTACHMENT_TYPE;

typedef struct{

    u8 Pin_Number;
    PIN_DIRECTION_TYPE Pin_Direction;
    PIN_INTERNAL_ATTACHMENT_TYPE Pin_InternalAttach;
    PIN_OUTPUT_CURRENT Pin_OutPut_Current;

}PORT_CONFIG_TYPE;

void DIO_voidInit_Pin(const PORT_CONFIG_TYPE *Copy_Pin);
void DIO_voidWriteChannel(DIO_CHANNEL_TYPE Copy_enumChannel, DIO_LEVEL_TYPE Copy_enumLevel_type);


#endif