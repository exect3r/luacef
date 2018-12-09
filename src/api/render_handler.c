#include "../luacef.h"

#include "include/capi/cef_render_handler_capi.h"

typedef struct luacef_RenderHandler{

	cef_render_handler_t self;

	lua_State *L;
	int ref;

} luacef_RenderHandler;

#define RH(fn) \
	LCEF_API(RenderHandler, fn)

#define RH_N(fn) \
	LCEF_API_N(RenderHandler, fn)

#define RH_M(mname) \
	LCEF_M(RenderHandler, mname)

#define SELF luacef_RenderHandler

static const char __GetAccessibilityHandler[] = "GetAccessibilityHandler";
static const char __GetRootScreenRect[] = "GetRootScreenRect";
static const char __GetViewRect[] = "GetViewRect";
static const char __GetScreenPoint[] = "GetScreenPoint";
static const char __GetScreenInfo[] = "GetScreenInfo";
static const char __OnPopupShow[] = "OnPopupShow";
static const char __OnPopupSize[] = "OnPopupSize";
static const char __OnPaint[] = "OnPaint";
static const char __OnCursorChange[] = "OnCursorChange";
static const char __StartDragging[] = "StartDragging";
static const char __UpdateDragCursor[] = "UpdateDragCursor";
static const char __OnScrollOffsetChanged[] = "OnScrollOffsetChanged";
static const char __OnIMECompositionRangeChanged[] = "OnIMECompositionRangeChanged";

struct _cef_accessibility_handler_t* CEF_CALLBACK RH_N(GetAccessibilityHandler)
	(struct luacef_RenderHandler* self)
{
	lua_rawgeti(self->L, LUA_REGISTRYINDEX, self->ref);
	if (lua_getfield(self->L, -1, __GetAccessibilityHandler)) {

		luacef_pushuserdata(self->L, self, __render_handler__); // 1

		lua_pcall(self->L, 1, 1, 8); // call

		return lua_isnil(self->L, -1) ? NULL : luacef_touserdata(self->L, -1);
	}

	return NULL;
}

int CEF_CALLBACK RH_N(GetRootScreenRect) 
	(struct luacef_RenderHandler* self, struct _cef_browser_t* browser, cef_rect_t* rect)
{
	lua_rawgeti(self->L, LUA_REGISTRYINDEX, self->ref);
	if (lua_getfield(self->L, -1, __GetRootScreenRect)) {

		luacef_pushuserdata(self->L, self, __render_handler__); // 1
		luacef_pushuserdata(self->L, browser, __browser__); // 2
		luacef_pushuserdata(self->L, rect, __rect__); // 3

		lua_pcall(self->L, 3, 1, 8); // call

		int ret = lua_tointeger(self->L, -1);
		return ret;
	}

	return 0;
}

int CEF_CALLBACK RH_N(GetViewRect) 
	(struct luacef_RenderHandler* self, struct _cef_browser_t* browser, cef_rect_t* rect)
{
	lua_rawgeti(self->L, LUA_REGISTRYINDEX, self->ref);
	if (lua_getfield(self->L, -1, __GetViewRect)) {

		luacef_pushuserdata(self->L, self, __render_handler__); // 1
		luacef_pushuserdata(self->L, browser, __browser__); // 2
		luacef_pushuserdata(self->L, rect, __rect__); // 3

		lua_pcall(self->L, 3, 1, 8); // call

		int ret = lua_tointeger(self->L, -1);
		return ret;
	}

	return 0;
}

int CEF_CALLBACK RH_N(GetScreenPoint) (struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	int viewX,
	int viewY,
	int* screenX,
	int* screenY)
{
	// todo
}


int CEF_CALLBACK RH_N(GetScreenInfo)(struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	struct _cef_screen_info_t* screen_info)
{

}

void CEF_CALLBACK RH_N(OnPopupShow)(struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	int show)
{

}

void CEF_CALLBACK RH_N(OnPopupSize)(struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	const cef_rect_t* rect)
{

}

void CEF_CALLBACK RH_N(OnPaint)(struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	cef_paint_element_type_t type,
	size_t dirtyRectsCount,
	cef_rect_t const* dirtyRects,
	const void* buffer,
	int width,
	int height)
{

}

void CEF_CALLBACK RH_N(OnCursorChange)(
	struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	cef_cursor_handle_t cursor,
	cef_cursor_type_t type,
	const struct _cef_cursor_info_t* custom_cursor_info)
{

}

int CEF_CALLBACK RH_N(StartDragging)(struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	struct _cef_drag_data_t* drag_data,
	cef_drag_operations_mask_t allowed_ops,
	int x,
	int y)
{

}

void CEF_CALLBACK RH_N(UpdateDragCursor)(struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	cef_drag_operations_mask_t operation)
{

}

void CEF_CALLBACK RH_N(OnScrollOffsetChanged)(
	struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	double x,
	double y)
{

}

void CEF_CALLBACK RH_N(OnIMECompositionRangeChanged)(
	struct luacef_RenderHandler* self,
	struct _cef_browser_t* browser,
	const cef_range_t* selected_range,
	size_t character_boundsCount,
	cef_rect_t const* character_bounds)
{

}

// api =========================

RH(new)
{
	size_t sz = sizeof(SELF);
	SELF *p = calloc(1, sz);
	p->self.base.size = sz;
	p->L = L;

	if (lua_istable(L, 1)) {
		lua_pushvalue(L, 1);
		p->ref = luaL_ref(L, LUA_REGISTRYINDEX);

		if (lua_getfield(L, 1, __GetAccessibilityHandler))
			p->self.get_accessibility_handler = (void*)RH_N(GetAccessibilityHandler);

		if (lua_getfield(L, 1, __GetRootScreenRect))
			p->self.get_root_screen_rect = (void*)RH_N(GetRootScreenRect);

		if (lua_getfield(L, 1, __GetViewRect))
			p->self.get_view_rect = (void*)RH_N(GetViewRect);

		if (lua_getfield(L, 1, __GetScreenPoint))
			p->self.get_screen_point = (void*)RH_N(GetScreenPoint);

		if (lua_getfield(L, 1, __GetScreenInfo))
			p->self.get_screen_info = (void*)RH_N(GetScreenInfo);

		if (lua_getfield(L, 1, __OnPopupShow))
			p->self.on_popup_show = (void*)RH_N(OnPopupShow);

		if (lua_getfield(L, 1, __OnPopupSize))
			p->self.on_popup_size = (void*)RH_N(OnPopupSize);

		if (lua_getfield(L, 1, __OnPaint))
			p->self.on_paint = (void*)RH_N(OnPaint);

		if (lua_getfield(L, 1, __OnCursorChange))
			p->self.on_cursor_change = (void*)RH_N(OnCursorChange);

		if (lua_getfield(L, 1, __StartDragging))
			p->self.start_dragging = (void*)RH_N(StartDragging);

		if (lua_getfield(L, 1, __UpdateDragCursor))
			p->self.update_drag_cursor = (void*)RH_N(UpdateDragCursor);

		if (lua_getfield(L, 1, __OnScrollOffsetChanged))
			p->self.on_scroll_offset_changed = (void*)RH_N(OnScrollOffsetChanged);

		if (lua_getfield(L, 1, __OnIMECompositionRangeChanged))
			p->self.on_ime_composition_range_changed = (void*)RH_N(OnIMECompositionRangeChanged);
	}
	else {
		lua_newtable(L);
		p->ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}

	luacef_pushudata(L, p, __render_handler__);
	return 1;
}

RH(index)
{
	SELF *p = luacef_touserdata(L, 1);
	if (!p) return 0;

	const char *i = lua_tostring(L, 2);

	lua_rawgeti(L, LUA_REGISTRYINDEX, p->ref);
	lua_pushvalue(L, -1);

	if (!strcmp(i, __release__))
		;// free

	else if (!strcmp(i, __GetAccessibilityHandler))
		lua_getfield(L, -1, __GetAccessibilityHandler);

	else if (!strcmp(i, __GetRootScreenRect))
		lua_getfield(L, -1, __GetRootScreenRect);

	else if (!strcmp(i, __GetViewRect))
		lua_getfield(L, -1, __GetViewRect);

	else if (!strcmp(i, __GetScreenPoint))
		lua_getfield(L, -1, __GetScreenPoint);

	else if (!strcmp(i, __GetScreenInfo))
		lua_getfield(L, -1, __GetScreenInfo);

	else if (!strcmp(i, __OnPopupShow))
		lua_getfield(L, -1, __OnPopupShow);

	else if (!strcmp(i, __OnPopupSize))
		lua_getfield(L, -1, __OnPopupSize);

	else if (!strcmp(i, __OnPaint))
		lua_getfield(L, -1, __OnPaint);

	else if (!strcmp(i, __OnCursorChange))
		lua_getfield(L, -1, __OnCursorChange);

	else if (!strcmp(i, __StartDragging))
		lua_getfield(L, -1, __StartDragging);

	else if (!strcmp(i, __UpdateDragCursor))
		lua_getfield(L, -1, __UpdateDragCursor);

	else if (!strcmp(i, __OnScrollOffsetChanged))
		lua_getfield(L, -1, __OnScrollOffsetChanged);

	else if (!strcmp(i, __OnIMECompositionRangeChanged))
		lua_getfield(L, -1, __OnIMECompositionRangeChanged);

	else return 0;

	return 1;
}

RH(newindex)
{
	SELF *p = luacef_touserdata(L, 1);
	if (!p) return 0;

	const char* i = lua_tostring(L, 2);

	lua_rawgeti(L, LUA_REGISTRYINDEX, p->ref);
	if (!lua_isfunction(L, 3)) return 0;
	lua_pushvalue(L, 3);

	if (!strcmp(i, __GetAccessibilityHandler)) {
		lua_setfield(L, -2, __GetAccessibilityHandler);
		p->self.get_accessibility_handler = (void*)RH_N(GetAccessibilityHandler);
	}

	else if (!strcmp(i, __GetRootScreenRect)) {
		lua_setfield(L, -2, __GetRootScreenRect);
		p->self.get_root_screen_rect = (void*)RH_N(GetRootScreenRect);
	}

	else if (!strcmp(i, __GetViewRect)) {
		lua_setfield(L, -2, __GetViewRect);
		p->self.get_view_rect = (void*)RH_N(GetViewRect);
	}

	else if (!strcmp(i, __GetScreenPoint)) {
		lua_setfield(L, -2, __GetScreenPoint);
		p->self.get_screen_point = (void*)RH_N(GetScreenPoint);
	}

	else if (!strcmp(i, __GetScreenInfo)) {
		lua_setfield(L, -2, __GetScreenInfo);
		p->self.get_screen_info = (void*)RH_N(GetScreenInfo);
	}

	else if (!strcmp(i, __OnPopupShow)) {
		lua_setfield(L, -2, __OnPopupShow);
		p->self.on_popup_show = (void*)RH_N(OnPopupShow);
	}

	else if (!strcmp(i, __OnPopupSize)) {
		lua_setfield(L, -2, __OnPopupSize);
		p->self.on_popup_size = (void*)RH_N(OnPopupSize);
	}

	else if (!strcmp(i, __OnPaint)) {
		lua_setfield(L, -2, __OnPaint);
		p->self.on_paint = (void*)RH_N(OnPaint);
	}

	else if (!strcmp(i, __OnCursorChange)) {
		lua_setfield(L, -2, __OnCursorChange);
		p->self.on_cursor_change = (void*)RH_N(OnCursorChange);
	}

	else if (!strcmp(i, __StartDragging)) {
		lua_setfield(L, -2, __StartDragging);
		p->self.start_dragging = (void*)RH_N(StartDragging);
	}

	else if (!strcmp(i, __UpdateDragCursor)) {
		lua_setfield(L, -2, __UpdateDragCursor);
		p->self.update_drag_cursor = (void*)RH_N(UpdateDragCursor);
	}

	else if (!strcmp(i, __OnScrollOffsetChanged)) {
		lua_setfield(L, -2, __OnScrollOffsetChanged);
		p->self.on_scroll_offset_changed = (void*)RH_N(OnScrollOffsetChanged);
	}

	else if (!strcmp(i, __OnIMECompositionRangeChanged)) {
		lua_setfield(L, -2, __OnIMECompositionRangeChanged);
		p->self.get_accessibility_handler = (void*)RH_N(OnIMECompositionRangeChanged);
	}

	return 0;
}

RH(len)
{
	lua_pushinteger(L, sizeof(SELF));
	return 1;
}

RH(unm)
{
	SELF *p = luacef_toudata(L, 1);

	lua_pushlightuserdata(L, p);
	return 1;
}

RH_M(meta)
{
	{ "__unm", RH_N(unm) },
	{ "__len", RH_N(len) },
	{ "__index", RH_N(index) },
	{ "__newindex", RH_N(newindex) },
	LUAREGEND
};

// register =========================

void RH_N(reg)(lua_State *L)
{
	luaL_newmetatable(L, __render_handler__);
	luaL_setfuncs(L, RH_N(meta), 0);
	lua_pop(L, 1);

	lua_pushcfunction(L, RH_N(new));
	lua_setfield(L, -2, "newRenderHandler");
}