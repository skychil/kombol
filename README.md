# kombol
Combo-based keymap for a Kyria Split Keyboad (QMK)

![SkyChil_Layout](https://user-images.githubusercontent.com/72839499/109599042-878b8080-7ae8-11eb-8c5c-33f68d6a07be.png)
[View on keyboard-layout-editor.com](http://www.keyboard-layout-editor.com/#/gists/c77544667b70d4c1fbf701af219d2cd7)

### My use case
Programming in Vim, on Sway Arch Linux

### Principles

Keep it simple.
Keep it ergo.
Test everything.

Optimal layout is specific to an individual's biomechanics, keyboard hardware, and use case. Do not assume what is best for others will be best for you.


### My Favorite Features
1. Combo based Symbols layer, including ' " ? : < > and double symbol shortcuts () [] {} <> '' "" ``
1. Backspace next to right pinky
1. Nav Layer (Arrow Keys, Home/End)
1. Shifts, Space, and Enter on home position thumb keys
1. Page Up/Dn, Undo/Redo on Rotary Encoders
1. Colemak DHm

### Drawbacks:
1. Mod locations are not symmetric
1. Learning it made typing on "normal" keyboards feel slow

<details>
  <summary>Features tested and NOT used</summary>
  
  * Symbols on a layer. Symbols on combos tested more ergonomic, faster, and more enjoyable.
  * Arrow keys on mnei / neio (qwerty hjkl / jkl;). As a long time vim user I was expecting to prefer mnei. However, testing revealed neiu (jkli) to be more ergo because it put the the most frequent keys (down and right) on my strongest two fingers (middle and ring). 
  * Numbers in a line on the home row / top row. The numpad tested fastest and most usable to me, which was unexpected.
  * F keys in a line on the upper row / on the numpad. F keys on the home row tested fastest, because F1-F5 are the most common.
  * All 4 "Home Row Mods". Having mods on the index fingers tested poorly because they locked out 6 alpha keys per side. Shift on home thumb keys tested better for me, which I was not expecting. Home row mods also tested poorly with Colemak DHm, as the high speed rolls caused accidental triggering.
  * Backspace on a home thumb key. I thought backspace would be best ona thumb key because it is usually pressed and held. Testing revealed that timing of the release was actually more important, and the pinky was more precise than the thumb. If I was using qwerty I would put backspace on ; for the same reason.
  * All other combo locations. I tried over 100 combo key pairs and kept the most ergonomic. The runners up are in the layout image as 'ghosted' keys, and can be used if needed.
  * Opposite hand layer activation (like miryoku). Single hand layer activation tested better for my ergonomics and spees (unexpected).
  * Tap dances like CCCACV and dotSpaceShift. Testing revealed they were too slow for high speed use.
  * Common words as plover combos across both hands. For example, "the" as combo(t, e). I tried for a long time to get this to work. In the end they didn't save enough key presses to be worth the accidental triggering. 
</details>

<details>
<summary>QMK Combo Limitations</summary>

  QMK Combos are amazing, but they are half baked.

  At the time I designed my layout, combos required massive boilerplate with silly things like counting and defining the total number of combos. I used a C preprocessor file from the community to make it tractable. I wish all that functionality was incorporated into QMK so more people could easily use combos.

  Combos also didn't work with home row mods, record macro keycodes, or tap dance keys, and this was not well documented. Once home row mods and combos are allowed on the same key, I will likely alter my mod locations.

  See also:
  https://precondition.github.io/home-row-mods#using-mod-taps-in-combos
</details>

<details>
  <summary>## Inspired by</summary>

https://www.reddit.com/r/ErgoMechKeyboards/comments/ifrd24/my_36_key_layout_with_only_2_layers_and_lots_of/
https://github.com/manna-harbour/miryoku
https://colemakmods.github.io/mod-dh/
https://forum.colemak.com/topic/2315-dreymars-big-bag-of-keyboard-tricks-main-topic/
https://github.com/sevanteri/qmk_firmware/tree/master/users/sevanteri
https://www.reddit.com/r/ErgoMechKeyboards/comments/hdm3mr/kyria_comprehensive_layers_system/
Drsnah, Vlad, Mirak
</details>

<details>
  <summary>## Hardware</summary>

$34  Kyria Rev 1.2 PCB kit w/ LEDs
$8  Low profile Mill Max sockets
$39  Elite-C 3.1 microcontrollers
$72  62g Zilents v2 "silent tactile blue" switches
$10  Rotary encoders & knobs
$41  Splitkb Clear Low Profile Plate Case
$84  PMK Keycaps: Standard DSA & Flat
$6  TTRS Cable
$15 GRIFITI Fat Wrist Pads (grinded to size)
(Had)  USB-C cable
(Had)  Bumpers for tenting
Total: $309


### Favorite Hardware Features

1. Kyria columnar stagger
1. Kyria thumb arc position and radius
1. Split
1. Tilting and tenting
1. Feel of pressing a single 62g Zilents
1. Lower profile thumb keys
1. DSA keycaps
1. Rotary Encoders
1. Rainbow RGB (unexpected)

### Drawbacks
1. Plate case required heavy modification (see below)
1. TTRS & USB cables are awkward
1. Lack of dedicated number row for occasional use (numpad layer is tedious for mixed numbers and alphas)
1. Flat thumb keycaps are a great height but have no sculpting
1. Pressing two 62g zilents with one finger (e.g. for combos) is a little heavy
1. Upper thumb keys are not ergo enough to be useful
1. The 1u solder pads under the 2u thumb keys are rotated 90 degrees, which messes up the uniformity of the thumb arc and prevents non 4-way symmetric stems (like Choch low pro).
1. Wrist rests required heavy modification (cutting and grinding)

### Tried and NOT used
* Cherry Profile keycaps. Combos were harder on cherry profile keycaps because of the row height differences and tall height. Uniform height flater DSA profile keycaps tested much better for combos.
* All 2u thumb keys. 2u keys took more effort to press and were less comfortable than the 1u thumb keys. I ended up deconstructing and re-building my board with all 1u keys and wish I had gone all 1u from the start.

 
Splitkb Plate Case Modifications

1. The pcb was just floating between the two acrylic layers, so removing keycaps pulls directly on the solder connections and moves the pcb up and down. I put bumpers between the top plate and pcb to fix this.
1. The case resting flat on the desk was very uncomfortable for me. It needed tilting and tenting to be usable.
   * I tried Lego tenting but it was difficult to construct the right angles with Legos. When I finally got it, it made the board too high off the desk which was also uncomfortable.
   * I ended up ditching the legos and using stick on bumpers to get the perfect tilt & tent. This was time consuming because each corner needed a different height and location, and they had to be exactly matched or the keyboard would wobble.
1. With any tilting and tenting the plate case becomes quite high off the table, but it's only because of the acrylic on the bottom outside corner. I ended up grinding away the acrylic and a bit of the pcb on the bottom outside corners. This made it lower profile, and was worth the effort, but created refraction problems with the corner RGBs shining into the grinded edge. I regrinded a notch around the LEDs and had to put electrical tape over the sides so the light didn't shine into them.

</details>

<details>
  <summary>## Final thoughts</summary>

Custom keyboards are a fun hobby, but a large investment of time and money. It took months of researching, ordering, waiting, building, and tweaking to get useable hardware. Then months of designing, programming, testing, and debugging to get a comfortable layout.

In time vendors will hopefully make this process cheaper and easier.

I created a lovely keyboard, but it's still not perfect. I would prefer one that was: full wireless, lighter weight, lower profile, had easily adjustable tent & tilt, matching wrist rests, and a number row. Something like a cross between a Kyria/Elora and a GergoPlex Heavy.

</details>
