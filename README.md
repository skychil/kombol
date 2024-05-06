# The Kombol Layout 2.0

A combo-based layout for Ergonomic Mechanical Keyboards, implemented in QMK.

![Kombol_Layout_1_1](https://user-images.githubusercontent.com/72839499/130539776-64c081e4-e99b-4d23-a7e8-4db67cdaea16.png)

[View on keyboard-layout-editor.com](http://www.keyboard-layout-editor.com/#/gists/c77544667b70d4c1fbf701af219d2cd7)


### Features
1. Combos for Symbols!
  1. Vertical combos for @ # $ % ^ & *
  1. Horizontal combos for () [] {} <>
1. Layers for:
  1. Navigation
  1. Number Pad
  1. Window Management
  1. Function Keys
1. Ergonomic Locations for:
  1. Escape: next to left pinky
  1. Backspace: next to right pinky
  1. Enter: under right thumb
  1. Shift: under both thumbs
  1. Ctrl: next to left thumb
  1. Layer Activation: next to thumbs
1. Rotary Encoders for:
  1. Page Up/Dn
  1. Undo/Redo (zy)
  1. Undo/Redo (zZ)
  1. Volume
  1. Zoom
1. Colemak DHm for alpha keys

### Optimal Use Case
* Software Development in Vim using a tiling window manager
* Large hands with strong middle and ring fingers
* Preference for same hand mod/layer activation
  * The alternative is opposite hand activation like [miryoku](https://github.com/manna-harbour/miryoku)

### Design Principles
Keep it simple.
Keep it ergo.
Use the home row as much as possible.
Test everything!

Remember: Optimal Layout is specific to an individual's biomechanics, keyboard hardware, and use case.

### Why Symbols on Combos
* Combos are incredibly fast
* Combos are easy to remember
* Commonly shifted symbols like : and are " are faster (and more ergo) as combos
* Moving ' and " to combos frees up a great key for backspace
* Symbols are typically pressed and released, which is ideal for combos
  * Held keys like arrow keys are tiring as combos because they require you to hold two keys
* Double symbols like <>, "" make great combos
  * A left arrow is added to position the cursor in between
  * They work in every application and website
* Having all symbols on the base layer is ideal for programming
  * Compare with the common practice of: some symbols on the base layer, some on the Shift layer, and some on a separate "Symbols" layer

<details>
<summary>1 Finger vs 2 Finger Combos</summary>

  Vertical Combos (like @#$%) and Horizontal Index Finger Combos (+|) use 1 finger to activate
  * You can think of these combos as another key in the space between two keys
  * These combos are fast and ergonomic because they are close to the home row
  * Accidental activation of 1 finger combos is rare

  All other Combos use 2 fingers to activate
  * Press both keys together, like stenography/plover
  * Accidental activation of 2 finger combos may occur at high typing speeds
    * Reducing COMBO_TERM helps to minimize accidental activations
      * Set COMBO_TERM as low as possible while still allowing consistent activation of combos
      * COMBO_TERM_PER_COMBO can be used for fine tuning per combo
      * If accidental activation still occurs, remove the offending combos from your layout

</details>

<details>
  <summary>Features tested and NOT used</summary>

  1. Symbols on a symbols layer
     * Symbols on combos tested more ergonomic, faster, and more enjoyable
  1. Arrow keys on mnei and neio (qwerty hjkl and jkl;)
     * As a long time vim user I was expecting to prefer mnei
     * Testing revealed neiu (jkli) to be most ergo because it put the the more frequent keys (down and right) on my strongest two fingers (middle and ring)
  1. Numbers on the home row, numbers on the top row
     * The numpad layout tested fastest and most usable, which I also did not expect.
  1. F keys on the top row only, F keys on the home row only, F keys on the numpad
     * F keys on the left hand tested best. Most important is having F1-F5 on the home row, since they are used the most.
  1. [Home Row Mods](https://precondition.github.io/home-row-mods#using-mod-taps-in-combos) for all mods
     * Having mods on the index fingers tested poorly because they locked out 6 alpha keys per side
     * Shift on home thumb keys tested better, which I was not expecting
     * Home row mods tested poorly with Colemak DHm because the high speed rolls caused accidental triggering
  1. Backspace on a home thumb key
     * I thought backspace would be best on a home thumb because it is often pressed and held
     * Testing revealed that timing of the release was actually most important, and the pinky was more precise than the thumb
     * If I were using qwerty I would test backspace on the ; key
  1. Other combo locations
     * I tried over 100 combo pairs and only used the most ergonomic
     * The runners up are in the layout image as 'ghosted' keys, and can be used if needed
  1. Opposite hand mod/layer activation (like miryoku)
     * Same hand mod/layer activation tested faster and more natural for my brain
  1. Tap Dances (like CCCACV and dotSpaceShift)
     * Testing revealed them to be too slow compared to combos
  1. Common words as plover combos across both hands
     * For example, "the" as combo(t, e)
     * Extensive testing revealed they didn't save enough key presses to be worth the mental overhead and accidental triggering
</details>


<details>
  <summary>Inspired by</summary>

  [ifrd24](https://www.reddit.com/r/ErgoMechKeyboards/comments/ifrd24/my_36_key_layout_with_only_2_layers_and_lots_of/)

  [miryoku](https://github.com/manna-harbour/miryoku)

  [Colemak DHm](https://colemakmods.github.io/mod-dh/)

  [DreymaR](https://dreymar.colemak.org/)

  [sevanteri](https://github.com/sevanteri/qmk_firmware/tree/master/users/sevanteri)

</details>

<details>
  <summary>Hardware</summary>
 
  ![rightside](https://user-images.githubusercontent.com/72839499/113330394-ab5f0380-92ec-11eb-9613-ab4bc35da60b.jpg)
 
  ![leftside](https://user-images.githubusercontent.com/72839499/113330256-84083680-92ec-11eb-991e-735980d54327.jpg)

  ![back](https://user-images.githubusercontent.com/72839499/113330419-b3b73e80-92ec-11eb-8ad8-32c32e08f94b.jpg)



  Price | Part
  ----- | ----
  $34 | Kyria Rev 1.2 PCB kit w/ LEDs
  $8 | Low profile Mill Max sockets
  $39 | Elite-C 3.1 microcontrollers
  $72 | 62g Zilents v2 "silent tactile blue" switches
  $10 | Rotary encoders & knobs
  $41 | Splitkb Clear Low Profile Plate Case
  $84 | PMK Keycaps: Standard DSA & Flat
  $6 | TTRS Cable
  $15 | GRIFITI Fat Wrist Pads (cut & grinded to size)
  (Had) | USB-C cable
  (Had) | Bumpers for tenting

Total: $309


### Favorite Hardware Features

1. Tilting and tenting
1. Split
1. Rotary Encoders
1. Kyria columnar stagger
1. Kyria thumb arc position and radius
1. Lower profile thumb keycaps
1. DSA keycaps for combos

### Drawbacks
1. Plate case required heavy modification (see below)
1. TTRS & USB cables are awkward
1. Lack of dedicated number row for occasional use (numpad layer is tedious for mixed numbers and alphas)
1. Flat thumb keycaps are a great height but have no sculpting
1. Pressing two 62g zilents with one finger (e.g. for combos) is a little heavy
1. Upper thumb keys are not ergo enough to be useful
1. The 1u solder pads under the 2u thumb keys are rotated 90 degrees
   * This messes up the uniformity of the thumb arc and prevents non 4-way symmetric stems (like Choch low pro)
1. Wrist rests required heavy modification (cutting and grinding)

### Tried and NOT used
* Cherry Profile keycaps
  * Combos were harder on cherry profile keycaps because of the row height differences and tall height
  * Uniform height flater DSA profile keycaps tested much better for combos
* 2u thumb keys
  * Even with lube and high quality stabs, the 2u keys took too much effort to press and were less comfortable than the other 1u thumb keys
  * It was hard to get 2u keycaps, especially low profile
  * I deconstructed my board and re-built it with all 1u keys and was much happier (keep it simple)

 
Splitkb Plate Case Modifications

1. The pcb was just floating between the two acrylic layers, so removing keycaps pulls directly on the solder connections and moves the pcb up and down
   * I put bumpers between the top plate and pcb to fix this
1. The case resting flat on the desk was uncomfortable, and needed tilting and tenting to be usable
   * I tried Lego tenting but it was difficult to construct the right angles with Legos
     * When I finally got it, it made the board uncomfortably high off the desk
   * I ended up ditching the legos and using stick on bumpers to get the perfect tilt & tent
     * This was time consuming because each corner needed a different height, and they had to be perfectly balanced or the keyboard would wobble
1. With any tilting and tenting the plate case becomes quite high off the table, but it's only because of the acrylic on the bottom outside corner
   * I ended up grinding away the acrylic and a bit of the pcb on the bottom outside corners
     * This made it lower profile, and was worth the effort, but created refraction problems with the corner RGBs shining into the grinded edge
       * I regrinded a notch around the LEDs and put electrical tape over the sides so the light couldn't shine in

</details>

<details>
  <summary>Final thoughts</summary>

Custom keyboards are a fun hobby, but a large investment of time and money. It took months of researching, ordering, waiting, building, and tweaking to get useable hardware. Then months of designing, programming, testing, and debugging to get a comfortable layout.

In time vendors will hopefully make this process cheaper and easier.

I created wonderful hardware, but it's not perfect.
A better keyboard would be:
 * Full wireless
 * Lower profile
 * Lighter weight
 * More portable
 * More durable

and have:
 * Easily adjustable tent & tilt
 * Integrated wrist rests

Something like a cross between a Kyria/Elora and a GergoPlex Heavy. I also like the corne design

The real innovation is in the layout I created. I love using it, and hope it will inspire you when you design your own layout.
</details>
