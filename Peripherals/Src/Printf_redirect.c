/*
 * Printf_redirect.c
 *
 *  Created on: Dec 18, 2025
 *      Author: saman
 */

#include "Printf_redirect.h"

int _write(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
    ITM_SendChar(*ptr++);
  }
  return len;
}
