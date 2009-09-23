/*
 * mx-adjustment.h: Adjustment object
 *
 * Copyright 2008 OpenedHand
 * Copyright 2009 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Written by: Chris Lord <chris@openedhand.com>, inspired by GtkAdjustment
 * Port to Mx by: Robert Staudinger <robsta@openedhand.com>
 *
 */

#if !defined(MX_H_INSIDE) && !defined(MX_COMPILATION)
#error "Only <mx/mx.h> can be included directly.h"
#endif

#ifndef __MX_ADJUSTMENT_H__
#define __MX_ADJUSTMENT_H__

#include <glib-object.h>
#include <clutter/clutter.h>

G_BEGIN_DECLS

#define MX_TYPE_ADJUSTMENT            (mx_adjustment_get_type())
#define MX_ADJUSTMENT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MX_TYPE_ADJUSTMENT, MxAdjustment))
#define MX_IS_ADJUSTMENT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MX_TYPE_ADJUSTMENT))
#define MX_ADJUSTMENT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), MX_TYPE_ADJUSTMENT, MxAdjustmentClass))
#define MX_IS_ADJUSTMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MX_TYPE_ADJUSTMENT))
#define MX_ADJUSTMENT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), MX_TYPE_ADJUSTMENT, MxAdjustmentClass))

typedef struct _MxAdjustment          MxAdjustment;
typedef struct _MxAdjustmentPrivate   MxAdjustmentPrivate;
typedef struct _MxAdjustmentClass     MxAdjustmentClass;

/**
 * MxAdjustment:
 *
 * Class for handling an interval between to values. The contents of
 * the #MxAdjustment are private and should be accessed using the
 * public API.
 */
struct _MxAdjustment
{
  /*< private >*/
  GObject parent_instance;

  MxAdjustmentPrivate *priv;
};

/**
 * MxAdjustmentClass
 * @changed: Class handler for the ::changed signal.
 *
 * Base class for #MxAdjustment.
 */
struct _MxAdjustmentClass
{
  /*< private >*/
  GObjectClass parent_class;

  /*< public >*/
  void (* changed) (MxAdjustment *adjustment);
};

GType mx_adjustment_get_type (void) G_GNUC_CONST;

MxAdjustment *mx_adjustment_new          (gdouble         value,
                                              gdouble         lower,
                                              gdouble         upper,
                                              gdouble         step_increment,
                                              gdouble         page_increment,
                                              gdouble         page_size);
gdouble         mx_adjustment_get_value    (MxAdjustment *adjustment);
void            mx_adjustment_set_value    (MxAdjustment *adjustment,
                                              gdouble         value);
void            mx_adjustment_clamp_page   (MxAdjustment *adjustment,
                                              gdouble         lower,
                                              gdouble         upper);
void            mx_adjustment_set_values   (MxAdjustment *adjustment,
                                              gdouble         value,
                                              gdouble         lower,
                                              gdouble         upper,
                                              gdouble         step_increment,
                                              gdouble         page_increment,
                                              gdouble         page_size);
void            mx_adjustment_get_values   (MxAdjustment *adjustment,
                                              gdouble        *value,
                                              gdouble        *lower,
                                              gdouble        *upper,
                                              gdouble        *step_increment,
                                              gdouble        *page_increment,
                                              gdouble        *page_size);

void            mx_adjustment_interpolate  (MxAdjustment *adjustment,
                                              gdouble         value,
                                              guint           duration);

gboolean        mx_adjustment_get_elastic  (MxAdjustment *adjustment);
void            mx_adjustment_set_elastic  (MxAdjustment *adjustment,
                                              gboolean        elastic);

gboolean        mx_adjustment_clamp        (MxAdjustment *adjustment,
                                              gboolean        interpolate,
                                              guint           duration);

G_END_DECLS

#endif /* __MX_ADJUSTMENT_H__ */