// Return codes for success and failure error handling

#ifndef STATUS_H
#define STATUS_H

typedef enum {
  STATUS_OK = 0,
  STATUS_INVALID_ARGS,
  STATUS_UNIMPLEMENTED,
  STATUS_FAILURE,
  NUM_STATUS,
} Status;

#endif // STATUS_H