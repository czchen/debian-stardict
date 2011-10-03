/*
 * Copyright 2011 kubtek <kubtek@mail.com>
 *
 * This file is part of StarDict.
 *
 * StarDict is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * StarDict is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with StarDict.  If not, see <http://www.gnu.org/licenses/>.
 */

//Begin marshal
//hotkeyeditor.marshal: VOID:INT,INT

//glib-genmarshal --header hotkeyeditor.marshal > hotkeyeditor.marshal.h
#ifndef __g_cclosure_user_marshal_MARSHAL_H__
#define __g_cclosure_user_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:INT,INT (hotkeyeditor.marshal:1) */
extern void g_cclosure_user_marshal_VOID__INT_INT (GClosure     *closure,
                                                   GValue       *return_value,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint,
                                                   gpointer      marshal_data);

G_END_DECLS

#endif /* __g_cclosure_user_marshal_MARSHAL_H__ */


//glib-genmarshal --body hotkeyeditor.marshal > hotkeyeditor.marshal.c
#include	<glib-object.h>


#ifdef G_ENABLE_DEBUG
#define g_marshal_value_peek_boolean(v)  g_value_get_boolean (v)
#define g_marshal_value_peek_char(v)     g_value_get_char (v)
#define g_marshal_value_peek_uchar(v)    g_value_get_uchar (v)
#define g_marshal_value_peek_int(v)      g_value_get_int (v)
#define g_marshal_value_peek_uint(v)     g_value_get_uint (v)
#define g_marshal_value_peek_long(v)     g_value_get_long (v)
#define g_marshal_value_peek_ulong(v)    g_value_get_ulong (v)
#define g_marshal_value_peek_int64(v)    g_value_get_int64 (v)
#define g_marshal_value_peek_uint64(v)   g_value_get_uint64 (v)
#define g_marshal_value_peek_enum(v)     g_value_get_enum (v)
#define g_marshal_value_peek_flags(v)    g_value_get_flags (v)
#define g_marshal_value_peek_float(v)    g_value_get_float (v)
#define g_marshal_value_peek_double(v)   g_value_get_double (v)
#define g_marshal_value_peek_string(v)   (char*) g_value_get_string (v)
#define g_marshal_value_peek_param(v)    g_value_get_param (v)
#define g_marshal_value_peek_boxed(v)    g_value_get_boxed (v)
#define g_marshal_value_peek_pointer(v)  g_value_get_pointer (v)
#define g_marshal_value_peek_object(v)   g_value_get_object (v)
#else /* !G_ENABLE_DEBUG */
/* WARNING: This code accesses GValues directly, which is UNSUPPORTED API.
 *          Do not access GValues directly in your code. Instead, use the
 *          g_value_get_*() functions
 */
#define g_marshal_value_peek_boolean(v)  (v)->data[0].v_int
#define g_marshal_value_peek_char(v)     (v)->data[0].v_int
#define g_marshal_value_peek_uchar(v)    (v)->data[0].v_uint
#define g_marshal_value_peek_int(v)      (v)->data[0].v_int
#define g_marshal_value_peek_uint(v)     (v)->data[0].v_uint
#define g_marshal_value_peek_long(v)     (v)->data[0].v_long
#define g_marshal_value_peek_ulong(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_int64(v)    (v)->data[0].v_int64
#define g_marshal_value_peek_uint64(v)   (v)->data[0].v_uint64
#define g_marshal_value_peek_enum(v)     (v)->data[0].v_long
#define g_marshal_value_peek_flags(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_float(v)    (v)->data[0].v_float
#define g_marshal_value_peek_double(v)   (v)->data[0].v_double
#define g_marshal_value_peek_string(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_param(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_boxed(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_pointer(v)  (v)->data[0].v_pointer
#define g_marshal_value_peek_object(v)   (v)->data[0].v_pointer
#endif /* !G_ENABLE_DEBUG */


/* VOID:INT,INT (hotkeyeditor.marshal:1) */
void
g_cclosure_user_marshal_VOID__INT_INT (GClosure     *closure,
                                       GValue       *return_value G_GNUC_UNUSED,
                                       guint         n_param_values,
                                       const GValue *param_values,
                                       gpointer      invocation_hint G_GNUC_UNUSED,
                                       gpointer      marshal_data)
{
  typedef void (*GMarshalFunc_VOID__INT_INT) (gpointer     data1,
                                              gint         arg_1,
                                              gint         arg_2,
                                              gpointer     data2);
  register GMarshalFunc_VOID__INT_INT callback;
  register GCClosure *cc = (GCClosure*) closure;
  register gpointer data1, data2;

  g_return_if_fail (n_param_values == 3);

  if (G_CCLOSURE_SWAP_DATA (closure))
    {
      data1 = closure->data;
      data2 = g_value_peek_pointer (param_values + 0);
    }
  else
    {
      data1 = g_value_peek_pointer (param_values + 0);
      data2 = closure->data;
    }
  callback = (GMarshalFunc_VOID__INT_INT) (marshal_data ? marshal_data : cc->callback);

  callback (data1,
            g_marshal_value_peek_int (param_values + 1),
            g_marshal_value_peek_int (param_values + 2),
            data2);
}
//End marshal

//Begin
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include "hotkeyeditor.h"

enum {
	HOTKEY_CHANGED,
	LAST_SIGNAL
};

G_DEFINE_TYPE (StardictHotkeyEditor, stardict_hotkey_editor, GTK_TYPE_ENTRY)

#define parent_class stardict_hotkey_editor_parent_class

static guint signals[LAST_SIGNAL] = { 0 };

gboolean stardict_hotkey_editor_key_press(GtkWidget *widget,
  GdkEventKey *kevent)
{
	StardictHotkeyEditor *editor = STARDICT_HOTKEY_EDITOR(widget);
	if (! kevent->is_modifier) {
		guint mods = kevent->state;
 		mods &= ~GDK_MOD2_MASK;
		mods &= ~GDK_MOD4_MASK;
		gtk_entry_set_text(GTK_ENTRY(widget), gtk_accelerator_name(kevent->keyval,
		  (GdkModifierType)(mods)));
		g_signal_emit(editor, signals[HOTKEY_CHANGED], 0, kevent->keyval,
		  mods);
	}
	return TRUE;
}

void stardict_hotkey_editor_class_init(StardictHotkeyEditorClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
	signals[HOTKEY_CHANGED] = g_signal_new("hotkey-changed",
	  G_TYPE_FROM_CLASS(klass),
	  G_SIGNAL_RUN_FIRST,
	  G_STRUCT_OFFSET(StardictHotkeyEditorClass, hotkey_changed),
	  NULL, NULL,
	  g_cclosure_user_marshal_VOID__INT_INT,
	  G_TYPE_NONE, 2, G_TYPE_INT, G_TYPE_INT);
	widget_class->key_press_event = stardict_hotkey_editor_key_press;
}

void stardict_hotkey_editor_init(StardictHotkeyEditor *editor)
{
	gtk_editable_set_editable(GTK_EDITABLE(&editor->parent_instance), 0);
	editor->current_mods = 0;
}

StardictHotkeyEditor *stardict_hotkey_editor_new()
{
	StardictHotkeyEditor *editor;
	editor = (StardictHotkeyEditor *)g_object_new(STARDICT_TYPE_HOTKEY_EDITOR, NULL);
	return editor;
}
