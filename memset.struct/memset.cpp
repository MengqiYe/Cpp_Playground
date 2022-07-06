//
// Created by elsey on 2022/3/11.
//
#include <bits/types.h>
#include <cstdlib>
#include <string>
#include <cstring>

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef uint32_t tm_uoffset_t; /* offset is 4-byte unsigned integer */
typedef uint32_t tm_size_t; /* size is 4-byte unsigned integer */
typedef uint8_t tm_bool_t; /* bool is 1-byte unsigned integer */

typedef struct {
    int32_t orig_format; /* format of original model */
    int32_t sub_format; /* sub format for DLA model */
    tm_uoffset_t offset_vo_subgraphs; /* offset of TM2_Vector_offsets <offsets of subgraphs> */
    tm_uoffset_t offset_s_mname; /* offset of string <model name> */
} TM2_Model;

typedef struct {
    tm_size_t size; /* string size */
    tm_uoffset_t offset_data; /* offset of string data */
} TM2_String;

#define ALIGN(pos, alignbytes) (((pos) + ( alignbytes )-1) & ~(( alignbytes )-1))

uint32_t WriteTmFileAlign1(void* const start_ptr, uint32_t* cur_pos, const void* buf, const uint32_t buf_size)
{
    uint32_t buf_pos = *cur_pos;
    memcpy(start_ptr + *cur_pos, buf, buf_size);
    *cur_pos += buf_size;
    return buf_pos;
}

uint32_t WriteTmFileAlign4(void* const start_ptr, uint32_t* cur_pos, const void* buf, const uint32_t buf_size)
{
    *cur_pos = ALIGN(*cur_pos, 4);

    return WriteTmFileAlign1(start_ptr, cur_pos, buf, buf_size);
}

uint32_t WriteTmObject(void* const start_ptr, uint32_t* cur_pos, const void* buf, const uint32_t buf_size)
{
    return WriteTmFileAlign4(start_ptr, cur_pos, buf, buf_size);
}

int main() {
    uint32_t cur_pos = 0;
    void* start_ptr = (void *)malloc(1 << 30);

    TM2_Model tm_model;
    memset(&tm_model, 0, sizeof(TM2_Model));
    tm_model.orig_format = 3;
    tm_model.sub_format = 1 + 16 + 16 * 16;

    const std::string fname = "test data";
    TM2_String model_name;
    model_name.size = 1;
    model_name.offset_data = WriteTmFileAlign1(start_ptr, &cur_pos, "", sizeof(""));
    tm_model.offset_s_mname = WriteTmObject(start_ptr, &cur_pos, &model_name, sizeof(TM2_String));

    return 0;
}