
typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

long switch3 ( long *p1, long *p2, mode_t action){

    long result = 0;
    switch(action){
        case MODE_A:
            *p2 = *p1;
            result = *p2;
            break;
        case MODE_B:
            result = *p1 + *p2;
            *p1 = result;
            break;
        case MODE_C:
            *p1 = 51;
            result = *p2;
            break;
        case MODE_D:
            result = 27;
            *p1 = *p2;
            break;

        case MODE_E:
            result = 27;

        default:
            result = 12;

    }
    return result;
}