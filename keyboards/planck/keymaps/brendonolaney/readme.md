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

``` json
[{a:7},"Tab","'",",",".","P","Y","F","G","C","R","L","Back Space"],
["Ctrl","A","O","E","U","I","D","H","T","N","S","Enter"],
["Shift",";","Q","J","K","X","B","M","W","V","Z","Shift"],
["Hyper","Meh","Alt","Super","Lower",{w:2},"","Raise","Left","Up","Down","Right"],
[{a:6,w:12,d:true},"<h4>Lower (Num Pad)</h4>"],
[{a:7},"`","1","2","3","4","5","6","7","8","9","0","Back Space"],
["Ctrl","","","","","","","4","5","6","","Enter"],
["Shift","","","","","","0","1","2","3","","Shift"],
["Hyper","Meh","Alt","Super",{c:"#ff8800"},"Lower",{c:"#cccccc",w:2},"","Raise","Left","Up","Down","Right"],
[{a:6,w:12,d:true},"<h4>Raise (Symbols)</h4>"],
[{a:7},"~","!","@","#","$","%","^","&","*","(",")","Back Space"],
["Ctrl","","","","","","","-","=","/","\\","Enter"],
["Shift","","","","","","","_","+","?","|","Shift"],
["Hyper","Meh","Alt","Super","Lower",{w:2},"",{c:"#ff8800"},"Raise",{c:"#cccccc"},"Left","Up","Down","Right"],
[{a:6,w:12,d:true},"<h4>Left (Brackets)</h4>"],
[{a:7},"Tab","","","(",")","","","","","","","Back Space"],
["Ctrl","","","[","]","","","","","","","Enter"],
["Shift","","","{","}","","","","","","","Shift"],
["Hyper","Meh","Alt","Super","Lower",{w:2},"","Raise",{c:"#ff8800"},"Left",{c:"#cccccc"},"Up","Down","Right"],
[{a:6,w:12,d:true},"<h4>Up (Function)</h4>"],
[{a:7},"Tab","F1","F2","F3","F4","","","","","","","Back Space"],
["Ctrl","F5","F6","F7","F8","","","Print Scr","Scroll Lock","Pause","","Enter"],
["Shift","F9","F10","F11","F12","","","","Num Lock","Caps Lock","","Shift"],
["Hyper","Meh","Alt","Super","Lower",{w:2},"","Raise","Left",{c:"#ff8800"},"Up",{c:"#cccccc"},"Down","Right"],
[{a:6,w:12,d:true},"<h4>Down (Media)</h4>"],
[{a:7},"Tab","","","","","","","","","","","Back Space"],
["Ctrl","","Prev","Play","Next","","","","","","","Enter"],
["Shift","","Mute","Vol-","Vol+","","","","","","","Shift"],
["Hyper","Meh","Alt","Super","Lower",{w:2},"","Raise","Left","Up",{c:"#ff8800"},"Down",{c:"#cccccc"},"Right"],
[{a:6,w:12,d:true},"<h4>Right (Adjust)</h4>"],
[{a:7},"Tab","","","","","","","","","","","Back Space"],
["Ctrl","",{fa:[2]},"AudOn","AudOff","AudTog","","","BlTog","Brght+","Brght-","",{f:3},"Enter"],
[{f:3},"Shift","",{f:3},"MusOn",{f:3},"MusOff",{f:3},"MusTog","","",{f:3},"BlMode",{f:3},"Hue+",{f:3},"Hue-","",{f:3},"Shift"],
[{f:3},"Hyper",{f:3},"Meh",{f:3},"Alt",{f:3},"Super",{f:3},"Lower",{w:2},"",{f:3},"Raise",{f:3},"Left",{f:3},"Up",{f:3},"Down",{c:"#ff8800",f:3},"Right"],
[{c:"#cccccc",a:6,f:3,w:12,d:true},"<h4>Nav (Lower + Raise)</h4>"],
[{a:7,f:3},"Esc",{f:3},"Pgup",{f:3},"Home",{f:3},"Up",{f:3},"End","","","","","",{f:3},"Ins",{f:3},"Del"],
[{f:3},"Ctrl",{f:3},"Pgdn",{f:3},"Left",{f:3},"Down",{f:3},"Right","","","","","","",{f:3},"Enter"],
[{f:3},"Shift","","","","","","","","","","",{f:3},"Shift"],
[{f:3},"Hyper",{f:3},"Meh",{f:3},"Alt",{f:3},"Super",{c:"#ff8800",f:3},"Lower",{c:"#cccccc",w:2},"",{c:"#ff8800",f:3},"Raise",{c:"#cccccc",f:3},"Left",{f:3},"Up",{f:3},"Down",{f:3},"Right"]
```
