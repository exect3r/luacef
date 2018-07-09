#include "luacef_types.h"

static int luacef_browser_host_new(lua_State* L)
{
	size_t sz = sizeof(cef_browser_host_t);
	cef_browser_host_t *h = calloc(1, sz);
	h->base.size = sz;

	//
	h->add_word_to_dictionary;
	h->close_browser;
	h->close_dev_tools;
	h->download_image;
	h->drag_source_ended_at;
	h->drag_source_system_drag_ended;
	h->drag_target_drag_enter;
	h->drag_target_drag_leave;
	h->drag_target_drag_over;
	h->drag_target_drop;
	h->find;
	h->get_browser;
	h->get_client;
	h->get_navigation_entries;
	//h->get_nstext_input_context;
	h->get_opener_window_handle;
	h->get_request_context;
	h->get_windowless_frame_rate;
	h->get_window_handle;
	h->get_zoom_level;
	//h->handle_key_event_after_text_input_client;
	//h->handle_key_event_before_text_input_client;
	h->has_dev_tools;
	h->has_view;
	h->invalidate;
	h->is_mouse_cursor_change_disabled;
	h->is_window_rendering_disabled;
	h->notify_move_or_resize_started;
	h->notify_screen_info_changed;
	h->print;
	h->print_to_pdf;
	h->replace_misspelling;
	h->run_file_dialog;
	h->send_capture_lost_event;
	h->send_focus_event;
	h->send_key_event;
	h->send_mouse_click_event;
	h->send_mouse_move_event;
	h->send_mouse_wheel_event;
	h->set_focus;
	h->set_mouse_cursor_change_disabled;
	h->set_windowless_frame_rate;
	h->set_zoom_level;
	h->show_dev_tools;
	h->start_download;
	h->stop_finding;
	h->try_close_browser;
	h->was_hidden;
	h->was_resized;

	luacef_pushuserdata(L, h, __browser_host__);
	return 1;
}

/*
	<void> BrowserHost:AddWordToDictionary(
		<str> word
	)
*/
static int luacef_browser_host_add_word_to_dictionary(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	const char* cs = lua_tostring(L, 2);

	cef_string_t word = { 0 };
	cef_string_from_utf8(cs, strlen(cs), &word);
	h->add_word_to_dictionary(h, &word);

	return 0;
}

/*
	<void> BrowserHost:CloseBrowser(
		<int> force_close
	)
*/
static int luacef_browser_host_close_browser(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	int force_close = lua_tointeger(L, 2);

	h->close_browser(h, force_close);

	return 0;
}

/*
	<void> BrowserHost:CloseDevTools()
*/
static int luacef_browser_host_close_dev_tools(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	h->close_dev_tools(h);

	return 0;
}

/*
	<> BrowserHost:DownloadImage()
*/
static int luacef_browser_host_download_image(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	// todo

	//h->download_image(h, );

	return 0;
}

/*
	<> BrowserHost:DragSourceEndedAt()
*/
static int luacef_browser_host_drag_source_ended_at(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	// todo
	//h->drag_source_ended_at()

	return 0;
}

/*
	<> BrowserHost:DragSourceSystemDragEnded()
*/
static int luacef_browser_host_drag_source_system_drag_ended(lua_State* L)
{

	// todo
	return 0;
}

/*
	<> BrowserHost:DragTargetDragEnter()
*/
static int luacef_browser_host_drag_target_drag_enter(lua_State* L)
{
	// todo
	return 0;
}

/*
	<> BrowserHost:DragTargetDragLeave()
*/
static int luacef_browser_host_drag_target_drag_leave(lua_State* L)
{
	// todo
	return 0;
}

/*
	<> BrowserHost:DragTargetDragOver()
*/
static int luacef_browser_host_drag_target_drag_over(lua_State* L)
{
	// todo
	return 0;
}

/*
	<> BrowserHost:DragTargetDrop()
*/
static int luacef_browser_host_drag_target_drop(lua_State* L)
{
	// todo
	return 0;
}

/*
	<> BrowserHost:Find()
*/
static int luacef_browser_host_find(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	// todo
	//h->find(h, )

	return 0;
}

/*
	<Browser> BrowserHost:GetBrowser()
*/
static int luacef_browser_host_get_browser(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	cef_browser_t *b = h->get_browser(h);

	luacef_pushuserdata(L, b, __browser__);
	return 1;
}

/*
	<Client> BrowserHost:GetClient()
*/
static int luacef_browser_host_get_client(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	cef_client_t *c = h->get_client(h);

	luacef_pushuserdata(L, c, __client__);
	return 1;
}

/*
	<void> Browser:GetNavigationEntries()
*/
static int luacef_browser_host_get_navigation_entries(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	// todo
	//h->get_navigation_entries(j. )

	return 0;
}

/*
	<void> Browser:GetNSTextInputContext()
*/
static int luacef_browser_host_get_nstext_input_context(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	//h->get_nstext_input_context(h);

	return 0;
}

/*
	<udata> Browser:GetOpenerWindowHandle()
	-> HWND
*/
static int luacef_browser_host_get_opener_window_handle(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	HWND handle = h->get_opener_window_handle(h);

	lua_pushlightuserdata(L, handle);
	return 1;
}

/*
	<RequestContext> Browser:GetRequestContext()
*/
static int luacef_browser_host_get_request_context(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	cef_request_context_t *rq = h->get_request_context(h);

	luacef_pushuserdata(L, rq, __request_context__);
	return 1;
}

/*
	<int> Browser:GetWindowlessFrameRate()
*/
static int luacef_browser_host_get_windowless_frame_rate(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	int frame_rate = h->get_windowless_frame_rate(h);

	lua_pushinteger(L, frame_rate);
	return 1;
}

/*
	<udata> Browser:GetWindowHandle()
	-> HWND
*/
static int luacef_browser_host_get_window_handle(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	HWND handle = h->get_window_handle(h);

	lua_pushlightuserdata(L, handle);
	return 1;
}

/*
	<num> Browser:GetZoomLevel()
*/
static int luacef_browser_host_get_zoom_level(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	double zl = h->get_zoom_level(h);

	lua_pushnumber(L, zl);
	return 1;
}

/*
	<> Browser:HandleKeyEventAfterTextInputClient()
*/
static int luacef_browser_host_handle_key_event_after_text_input_client(lua_State* L)
{
	// todo
	return 0;
}

/*
	<> Browser:HandleKeyEventBeforeTextInputClient()
*/
static int luacef_browser_host_handle_key_event_before_text_input_client(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	//MSG *msg = 
	// #ifdef WIN32 //


	//h->handle_key_event_before_text_input_client(h, )
	// todo
	return 0;
}

/*
	<bool> Browser:HasDevTools()
*/
static int luacef_browser_host_has_dev_tools(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	lua_pushboolean(L, h->has_dev_tools(h));
	return 1;
}

/*
	<bool> Browser:HasView()
*/
static int luacef_browser_host_has_view(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	lua_pushboolean(L, h->has_view(h));
	return 1;
}

/*
	<void> Browser:Invalidate(
		<int>	paint_element_type
	)
*/
static int luacef_browser_host_invalidate(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	int type = lua_tointeger(L, 2);

	h->invalidate(h, type);

	return 0;
}

/*
	<bool> Browser:IsMouseCursorChangeDisabled()
*/
static int luacef_browser_host_is_mouse_cursor_change_disabled(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	lua_pushboolean(L, h->is_mouse_cursor_change_disabled(h));
	return 1;
}

/*
	<bool> Browser:IsWindowRenderingDisabled()
*/
static int luacef_browser_host_is_window_rendering_disabled(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	lua_pushboolean(L, h->is_window_rendering_disabled(h));
	return 1;
}

/*
	<void> Browser:NotifyMoveOrResizeStarted()
*/
static int luacef_browser_host_notify_move_or_resize_started(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	h->notify_move_or_resize_started(h);

	return 0;
}

/*
	<void> Browser:NotifyScreenInfoChanged()
*/
static int luacef_browser_host_notify_screen_info_changed(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	h->notify_screen_info_changed(h);

	return 0;
}

/*
	<void> Browser:Print()
*/
static int luacef_browser_host_print(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	h->print(h);

	return 0;
}

/*
	<void> Browser:PrintToPDF(
		<str>				path,
		<PDFPrintSettings>	settings,
		<PDFPrintCallback>	callback
	)
*/
static int luacef_browser_host_print_to_pdf(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	const char *cs_path = lua_tostring(L, 2);
	cef_pdf_print_settings_t *pdf_s = NULL;
	cef_pdf_print_callback_t *pdf_cb = NULL;

	cef_string_t path = { 0 };
	cef_string_from_utf8(cs_path, strlen(cs_path), &path);

	h->print_to_pdf(h, &path, pdf_s, pdf_cb);

	return 0;
}

/*
	<void> Browser:ReplaceMisspelling(
		<str> word
	)
*/
static int luacef_browser_host_replace_misspelling(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	const char *cs = lua_tostring(L, 2);

	cef_string_t word = { 0 };
	cef_string_from_utf8(cs, strlen(cs), &word);
	h->replace_misspelling(h, &word);

	return 0;
}

/*
	<void> Browser:RunFileDialog()
*/
static int luacef_browser_host_run_file_dialog(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	//h->run_file_dialog()
	// todo

	return 0;
}

/*
	<void> Browser:SendCaptureLostEvent()
*/
static int luacef_browser_host_send_capture_lost_event(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	h->send_capture_lost_event(h);

	return 0;
}

/*
	<void> Browser:SendFocusEvent(
		<int> set_foccus
	)
*/
static int luacef_browser_host_send_focus_event(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	int setfocus = lua_tointeger(L, 2);

	h->send_focus_event(h, setfocus);

	return 0;
}

/*
	<void> Browser:SendKeyEvent(
		<KeyEvent>	event
	)
*/
static int luacef_browser_host_send_key_event(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	cef_key_event_t *ke = luacef_checkudata(L, 2, __key_event__);

	h->send_key_event(h, ke);

	return 0;
}

/*
	<void> Browser:SendMouseClickEvent(
		<MouseEvent>	event,
		<int>			button_type,
		<int>			mouse_up
		<int>			click_count
	)
*/
static int luacef_browser_host_send_mouse_click_event(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	cef_mouse_event_t *me = luacef_checkudata(L, 2, __mouse_event__);
	int type = lua_tointeger(L, 3);
	int up = lua_tointeger(L, 4);
	int count = lua_tointeger(L, 5);

	h->send_mouse_click_event(h, me, type, up, count);

	return 0;
}

/*
	<void> Browser:SendMouseMoveEvent(
		<MouseEvent>	event,
		<int>			mouse_leave,
	)
*/
static int luacef_browser_host_send_mouse_move_event(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	cef_mouse_event_t *me = luacef_checkudata(L, 2, __mouse_event__);
	int leave = lua_tointeger(L, 3);

	h->send_mouse_move_event(h, me, leave);

	return 0;
}

/*
	<void> Browser:SendMouseWheelEvent(
		<MouseEvent>	event,
		<int>			deltaX,
		<int>			deltaY
	)
*/
static int luacef_browser_host_send_mouse_wheel_event(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	cef_mouse_event_t *me = luacef_checkudata(L, 2, __mouse_event__);
	int dx = lua_tointeger(L, 3);
	int dy = lua_tointeger(L, 4);

	h->send_mouse_wheel_event(h, me, dx, dy);

	return 0;
}

/*
	<void> Browser:SetFocus(
		<bool> focus
	)
*/
static int luacef_browser_host_set_focus(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	int focus = lua_toboolean(L, 2);

	h->set_focus(h, focus);

	return 0;
}

/*
	<void> Browser:SetMouseCursorChangeDisabled(
		<bool> disabled
	)
*/
static int luacef_browser_host_set_mouse_cursor_change_disabled(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	int disabled = lua_toboolean(L, 2);

	h->set_mouse_cursor_change_disabled(h, disabled);

	return 0;
}

/*
	<void> Browser:SetWindowlessFrameRate(
		<int> frame_rate
	)
*/
static int luacef_browser_host_set_windowless_frame_rate(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	int frame_rate = lua_tointeger(L, 2);

	h->set_windowless_frame_rate(h, frame_rate);

	return 0;
}

/*
	<void> Browser:SetZoomLevel(
		<num>	zoom_level
	)
*/
static int luacef_browser_host_set_zoom_level(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	double zl = lua_tonumber(L, 2);

	h->set_zoom_level(h, zl);

	return 0;
}

/*
	<void> Browser:ShowDevTools(
		<WindowInfo>		window_info,
		<Client>			client,
		<BrowserSettings>	settings,
		<Point>				inspect_element_at	
	)
*/
static int luacef_browser_host_show_dev_tools(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	cef_window_info_t *wi = luacef_checkudata(L, 2, __window_info__);
	cef_client_t *c = luacef_checkudata(L, 3, __client__);
	cef_browser_settings_t *bs = luacef_checkudata(L, 4, __browser_settings__);
	cef_point_t *pt = luacef_checkudata(L, 5, __point__);

	h->show_dev_tools(h, wi, c, bs, pt);

	return 0;
}

/*
	<void> Browser:StartDownload(
		<str> url
	)
*/
static int luacef_browser_host_start_download(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	const char* cs = lua_tostring(L, 2);

	cef_string_t url = { 0 };
	cef_string_from_utf8(cs, strlen(cs), &url);
	h->start_download(h, &url);

	return 0;
}

/*
	<void> Browser:StopFinding(
		<int> clearSelection
	)
*/
static int luacef_browser_host_stop_finding(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	int clr_slt = lua_tointeger(L, 2);

	h->stop_finding(h, clr_slt);

	return 0;
}

/*
	<int> Browser:TryCloseBrowser()
*/
static int luacef_browser_host_try_close_browser(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	int ret = h->try_close_browser(h);

	lua_pushinteger(L, ret);
	return 1;
}

/*
	<void> Browser:WasHidden(
		<int> hidden
	)
*/
static int luacef_browser_host_was_hidden(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);
	int hidden = lua_tointeger(L, 2);

	h->was_hidden(h, hidden);

	return 0;
}

/*
	<void> Browser:WasResized()
*/
static int luacef_browser_host_was_resized(lua_State* L)
{
	cef_browser_host_t *h = luacef_touserdata(L, 1);

	h->was_resized(h);

	return 0;
}

static const luaL_Reg luacef_browser_host_m[] = {
	{ "AddWordToDictionary", luacef_browser_host_add_word_to_dictionary },
	{ "CloseBrowser", luacef_browser_host_close_browser },
	{ "CloseDevTools", luacef_browser_host_close_dev_tools },
	{ "DownloadImage", luacef_browser_host_download_image },
	{ "DragSourceEndedAt", luacef_browser_host_drag_source_ended_at },
	{ "DragSourceSystemDragEnded", luacef_browser_host_drag_source_system_drag_ended },
	{ "DragTargetDragEnter", luacef_browser_host_drag_target_drag_enter },
	{ "DragTargetDragLeave", luacef_browser_host_drag_target_drag_leave },
	{ "DragTargetDragOver", luacef_browser_host_drag_target_drag_over },
	{ "DragTargetDrop", luacef_browser_host_drag_target_drop },
	{ "Find", luacef_browser_host_find },
	{ "GetBrowser", luacef_browser_host_get_browser },
	{ "GetClient", luacef_browser_host_get_client },
	{ "GetNavigationEntries", luacef_browser_host_get_navigation_entries },
	{ "GetNSTextInputContext", luacef_browser_host_get_nstext_input_context },
	{ "GetOpenerWindowHandle", luacef_browser_host_get_opener_window_handle },
	{ "GetRequestContext", luacef_browser_host_get_request_context },
	{ "GetWindowlessFrameRate", luacef_browser_host_get_windowless_frame_rate },
	{ "GetWindowHandle", luacef_browser_host_get_window_handle },
	{ "GetZoomLevel", luacef_browser_host_get_zoom_level },
	{ "HandleKeyEventAfterTextInputClient", luacef_browser_host_handle_key_event_after_text_input_client },
	{ "HandleKeyEventBeforeTextInputClient", luacef_browser_host_handle_key_event_before_text_input_client },
	{ "HasDevTools", luacef_browser_host_has_dev_tools },
	{ "HasView", luacef_browser_host_has_view },
	{ "Invalidate", luacef_browser_host_invalidate },
	{ "IsMouseCursorChangeDisabled", luacef_browser_host_is_mouse_cursor_change_disabled },
	{ "IsWindowRenderingDisabled", luacef_browser_host_is_window_rendering_disabled },
	{ "NotifyMoveOrResizeStarted", luacef_browser_host_notify_move_or_resize_started },
	{ "NotifyScreenInfoChanged", luacef_browser_host_notify_screen_info_changed },
	{ "Print", luacef_browser_host_print },
	{ "PrintToPDF", luacef_browser_host_print_to_pdf },
	{ "ReplaceMisspelling", luacef_browser_host_replace_misspelling },
	{ "RunFileDialog", luacef_browser_host_run_file_dialog },
	{ "SendCaptureLostEvent", luacef_browser_host_send_capture_lost_event },
	{ "SendFocusEvent", luacef_browser_host_send_focus_event },
	{ "SendKeyEvent", luacef_browser_host_send_key_event },
	{ "SendMouseClickEvent", luacef_browser_host_send_mouse_click_event },
	{ "SendMouseMoveEvent", luacef_browser_host_send_mouse_move_event },
	{ "SendMouseWheelEvent", luacef_browser_host_send_mouse_wheel_event },
	{ "SetFocus", luacef_browser_host_set_focus },
	{ "SetMouseCursorChangeDisabled", luacef_browser_host_set_mouse_cursor_change_disabled },
	{ "SetWindowlessFrameRate", luacef_browser_host_set_windowless_frame_rate },
	{ "SetZoomLevel", luacef_browser_host_set_zoom_level },
	{ "ShowDevTools", luacef_browser_host_show_dev_tools },
	{ "StartDownload", luacef_browser_host_start_download },
	{ "StopFinding", luacef_browser_host_stop_finding },
	{ "TryCloseBrowser", luacef_browser_host_try_close_browser },
	{ "WasHidden", luacef_browser_host_was_hidden },
	{ "WasResized", luacef_browser_host_was_resized },
	{ NULL, NULL }
};

void luacef_browser_host_reg(lua_State* L)
{
	luaL_newmetatable(L, __browser_host__);
	luaL_setfuncs(L, luacef_browser_host_m, 0);
	lua_setfield(L, -1, __index__);

	//
}