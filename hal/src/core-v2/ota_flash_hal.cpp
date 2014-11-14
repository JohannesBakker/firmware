/**
 ******************************************************************************
 * @file    ota_flash_hal.cpp
 * @author  Matthew McGowan
 * @version V1.0.0
 * @date    25-Sept-2014
 * @brief
 ******************************************************************************
  Copyright (c) 2013-14 Spark Labs, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#if USE_WICED_SDK==1
#include "ota_flash_hal.h"
#include "dct_hal.h"
#include <cstring>

uint32_t HAL_OTA_FlashAddress()
{
    return 0;
}

uint32_t HAL_OTA_FlashLength()
{
    return 0;
}
    

void HAL_FLASH_Begin(uint32_t sFLASH_Address, uint32_t fileSize) 
{
}

uint16_t HAL_FLASH_Update(uint8_t *pBuffer, uint32_t bufferSize) 
{
    return 0;
}

void HAL_FLASH_End(void) 
{    
}


void copy_dct(void* target, uint16_t offset, uint16_t length) {
    void* data = dct_read_app_data(offset);
    memcpy(target, data, length);
}


void HAL_FLASH_Read_ServerAddress(ServerAddress* server_addr)
{
    copy_dct(server_addr, DCT_SERVER_ADDRESS_OFFSET, DCT_SERVER_ADDRESS_SIZE);
}


bool HAL_OTA_Flashed_GetStatus(void) 
{
    return false;
}

void HAL_OTA_Flashed_ResetStatus(void)
{    
}

void HAL_FLASH_Read_ServerPublicKey(uint8_t *keyBuffer)
{
    copy_dct(keyBuffer, DCT_SERVER_PUBLIC_KEY_OFFSET, EXTERNAL_FLASH_SERVER_PUBLIC_KEY_LENGTH);
}

void HAL_FLASH_Read_CorePrivateKey(uint8_t *keyBuffer)
{ 
    copy_dct(keyBuffer, DCT_DEVICE_PRIVATE_KEY_OFFSET, EXTERNAL_FLASH_CORE_PRIVATE_KEY_LENGTH);
}

#else

#include "../template/ota_flash_hal.c"

#endif

