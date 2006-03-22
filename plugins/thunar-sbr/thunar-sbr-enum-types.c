/* $Id$ */
/*-
 * Copyright (c) 2006 Benedikt Meurer <benny@xfce.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <glib/gi18n-lib.h>

#include <thunar-sbr/thunar-sbr-enum-types.h>



static GType case_renamer_mode_type;
static GType insert_mode_type;
static GType offset_mode_type;



GType
thunar_sbr_case_renamer_mode_get_type (void)
{
  return case_renamer_mode_type;
}



GType
thunar_sbr_insert_mode_get_type (void)
{
  return insert_mode_type;
}



GType
thunar_sbr_offset_mode_get_type (void)
{
  return offset_mode_type;
}



void
thunar_sbr_register_enum_types (ThunarxProviderPlugin *plugin)
{
  static const GEnumValue case_renamer_mode_values[] =
  {
    { THUNAR_SBR_CASE_RENAMER_MODE_LOWER, "THUNAR_SBR_CASE_RENAMER_MODE_LOWER", N_ ("lowercase"), },
    { THUNAR_SBR_CASE_RENAMER_MODE_UPPER, "THUNAR_SBR_CASE_RENAMER_MODE_UPPER", N_ ("UPPERCASE"), },
    { THUNAR_SBR_CASE_RENAMER_MODE_CAMEL, "THUNAR_SBR_CASE_RENAMER_MODE_CAMEL", N_ ("Camelcase"), },
    { 0,                                  NULL,                                 NULL,             },
  };

  static const GEnumValue insert_mode_values[] =
  {
    { THUNAR_SBR_INSERT_MODE_INSERT,    "THUNAR_SBR_INSERT_MODE_INSERT",    N_ ("Insert"),    },
    { THUNAR_SBR_INSERT_MODE_OVERWRITE, "THUNAR_SBR_INSERT_MODE_OVERWRITE", N_ ("Overwrite"), },
    { 0,                                NULL,                               NULL,             },
  };

  static const GEnumValue offset_mode_values[] =
  {
    { THUNAR_SBR_OFFSET_MODE_LEFT,  "THUNAR_SBR_OFFSET_MODE_LEFT",  N_ ("From left"),  },
    { THUNAR_SBR_OFFSET_MODE_RIGHT, "THUNAR_SBR_OFFSET_MODE_RIGHT", N_ ("From right"), },
    { 0,                            NULL,                           NULL,              },
  };

  case_renamer_mode_type = thunarx_provider_plugin_register_enum (plugin, "ThunarSbrCaseRenamerMode", case_renamer_mode_values);
  insert_mode_type = thunarx_provider_plugin_register_enum (plugin, "ThunarSbrInsertMode", insert_mode_values);
  offset_mode_type = thunarx_provider_plugin_register_enum (plugin, "ThunarSbrOffsetMode", offset_mode_values);
}




