#define SUCCEED           0
#define OPEN_FILE_ERROR   1
#define INSUFICENT_MEMORY 2
#define FAILED_ALLOCATION 3
#define ILLEGAL_VALUE     4
#define POR_BOLUDO        5

#define TYPE              uint8_t
#define DataSectionSize   2048
#define true              1
#define MAX_NAME_LEN      5000

#define PasswordLen(A) A->PasswordMax-A->PasswordMin+1
// Windows commands

// #define CLEAR "cls"
// #define PAUSE "pause"


// Linux commands

#define CLEAR "clear"
#define PAUSE "cd ."

