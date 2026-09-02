# Shared sources and features for all of @ykz89's keymaps.
#
# ykz89.c is entirely #ifdef POINTING_DEVICE_ENABLE, so it is only worth
# compiling on boards that have one. POINTING_DEVICE_ENABLE is resolved from
# the keyboard's features well before this file is included, so the test is
# safe here (builddefs/build_keyboard.mk:149 vs :479).
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
SRC += ykz89.c
endif

# Combos are defined in ykz89_combos.c, included into QMK's keymap introspection
# (NOT added to SRC) so `key_combos` is visible where ARRAY_SIZE() counts it.
#
# Under Vial the dynamic combo engine defines key_combos[] itself (see
# quantum/vial.c), so the static table must not be compiled in -- those boards
# create the "third thumb" combos in Vial's combo editor instead.
ifneq ($(strip $(VIAL_ENABLE)), yes)
INTROSPECTION_KEYMAP_C += ykz89_combos.c
endif

# Caps-word is part of the canonical layout (CW_TOGG on the navigation layer).
CAPS_WORD_ENABLE = yes
