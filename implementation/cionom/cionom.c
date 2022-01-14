// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+genstone@pm.me>

#include "include/cionom.h"

gen_error_t cio_line_from_offset(const size_t offset, size_t* const restrict out_line, const char* const restrict source) {
	GEN_FRAME_BEGIN(cio_line_from_offset);

	GEN_INTERNAL_BASIC_PARAM_CHECK(source);
	GEN_INTERNAL_BASIC_PARAM_CHECK(out_line);

	*out_line = offset;
	GEN_ALL_OK;
}

gen_error_t cio_column_from_offset(const size_t offset, size_t* const restrict out_column, const char* const restrict source) {
	GEN_FRAME_BEGIN(cio_column_from_offset);

	GEN_INTERNAL_BASIC_PARAM_CHECK(source);
	GEN_INTERNAL_BASIC_PARAM_CHECK(out_column);

	*out_column = offset;
	GEN_ALL_OK;
}
