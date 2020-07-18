# Brendon's Planck Layout

1. Remove QWERTY and Colemak
2. Remove Plover. Looks like this is a stenography thing that I will never use.
3. Trim the adjust layer back. I prefer the default Oryx configuration
4. Rename layers and add Nav, Function, and Media layers

## Notes

AG_NORM and AG_SWAP changes the position of alt and command(gui)

Audio: https://docs.qmk.fm/#/feature_audio?id=audio
- AU_ON - Turn Audio Feature on
- AU_OFF - Turn Audio Feature off
- AU_TOG - Toggle Audio Feature state

Music Mode: https://docs.qmk.fm/#/feature_audio?id=music-mode
- MU_ON - Turn music mode on
- MU_OFF - Turn music mode off
- MU_TOG - Toggle music mode
- MU_MOD - Cycle through the music modes:

MIDI Mode: https://docs.qmk.fm/#/feature_audio?id=midi-functionality
- MI_ON MIDI on
- MI_OFF MIDI off

Voices:
From what I can tell a voice is defined as a specific sound, and each is
assigned to a timer. These keys iterate the voices through different timers. The
specific effect is mysterious to me.

- MUV_IN Voice increase
- MUV_DE Voice decrease

Terminal: https://docs.qmk.fm/#/feature_terminal?id=terminal
TERM_ON and TERM_OFF terminal is a feature that allows you to use a text editor as a direct
terminal to the keyboard.

