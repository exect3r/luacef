#pragma once

#include "../luacef.h"

typedef struct luacef_resource_bundle_handler {

	cef_base_t base;

	int (CEF_CALLBACK *get_localized_string)(
		struct luacef_resource_bundle_handler*	self,
		int										string_id,
		cef_string_t*							string);

	int (CEF_CALLBACK *get_data_resource)(
		struct luacef_resource_bundle_handler*	self,
		int										resource_id,
		void**									data,
		size_t*									data_size);

	int (CEF_CALLBACK *get_data_resource_for_scale)(
		struct luacef_resource_bundle_handler*	self,
		int										resource_id,
		cef_scale_factor_t						scale_factor,
		void**									data,
		size_t*									data_size);

	lua_State *L;
	int ref;

} luacef_resource_bundle_handler;