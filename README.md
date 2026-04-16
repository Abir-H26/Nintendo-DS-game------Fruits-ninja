<h1>Fruit Ninja — Nintendo DS Game</h1>
<p><em>A microprogrammed embedded systems project built on the Nintendo DS architecture.</em></p>

<p>
This project implements a Fruit-Ninja–style game on the Nintendo DS, developed for the 
<strong>Systèmes Embarqués Microprogrammés</strong> course. It features two game modes, touchscreen slicing, 
sprite animations, sound effects, timers, interrupts, and dual-processor coordination between ARM9 and ARM7.
</p>

<hr>

<h2>Features Overview</h2>

<h3>Game Modes</h3>
<ul>
  <li><strong>Menu</strong> — lets the player select a mode using buttons or touchscreen.</li>
  <li><strong>Ananas Mode (Time Attack)</strong>
    <ul>
      <li>1-minute countdown</li>
      <li>Slice as many fruits as possible</li>
      <li>Countdown driven by Timer 0</li>
    </ul>
  </li>
  <li><strong>Pasteque Mode (Survival)</strong>
    <ul>
      <li>Slice all fruits</li>
      <li>Game ends if more than 5 fruits fall</li>
    </ul>
  </li>
</ul>

<hr>

<h2>System Architecture</h2>

<h3>Dual-Processor Model (ARM9 + ARM7)</h3>
<ul>
  <li><strong>ARM9</strong>
    <ul>
      <li>LCD TFT rendering</li>
      <li>Key input (A + arrows)</li>
      <li>Sends IPC messages to ARM7 for audio control</li>
    </ul>
  </li>
  <li><strong>ARM7</strong>
    <ul>
      <li>Touchscreen polling</li>
      <li>Audio playback</li>
    </ul>
  </li>
</ul>

<hr>

<h2>Timers & Interrupts</h2>
<ul>
  <li><strong>Timer 0</strong> — 1 ms interrupt for Ananas countdown</li>
  <li><strong>IRQ_VBLANK</strong> — screen updates for both modes</li>
  <li><strong>Keypad interrupts</strong> — play/pause/exit detection</li>
</ul>

<hr>

<h2>Graphics & Rendering</h2>

<h3>Main Engine (VRAM A)</h3>
<ul>
  <li><strong>Menu</strong> → Mode 5, BG0 (tiled)</li>
  <li><strong>Ananas</strong> → Mode 0, BG2 (tiled) — score + countdown</li>
  <li><strong>Pasteque</strong> → Mode 0, BG2 (tiled) — score + faults counter</li>
</ul>

<h3>Sub Engine (VRAM C)</h3>
<ul>
  <li><strong>Menu</strong> → Mode 5, BG2 (Extended Rotoscale) — highlighted mode selection</li>
  <li><strong>Game modes</strong> → Mode 0, BG2 (tiled) — rules + falling fruits</li>
</ul>

<hr>

<h2>Controls</h2>

<h3>Menu</h3>
<ul>
  <li><strong>A</strong> — launch selected mode</li>
  <li><strong>Left / Right</strong> — switch between Ananas and Pasteque</li>
  <li><strong>Touchscreen</strong> — select mode by tapping the corresponding area</li>
</ul>

<h3>In-Game (Ananas & Pasteque)</h3>
<ul>
  <li><strong>Left</strong> — exit to menu</li>
  <li><strong>Up</strong> — pause</li>
  <li><strong>Down</strong> — start</li>
  <li><strong>Touchscreen</strong> — slice fruits</li>
</ul>

<hr>

<h2>Audio</h2>
<ul>
  <li><strong>Background music (.mod)</strong> in menu</li>
  <li><strong>Sound effects (.wav)</strong> for:
    <ul>
      <li>Mode switching</li>
      <li>Fruit appearance</li>
    </ul>
  </li>
</ul>

<hr>

<h2>Sprites & Animation (VRAM D)</h2>
<ul>
  <li>Falling fruits (apples, bananas, pineapples) generated from random positions</li>
  <li>Puddle animation appears when fruits are cut</li>
  <li>Blade sprite follows touchscreen movement</li>
  <li>Blade disappears when touch is released</li>
</ul>

<hr>

<h2>Screenshots</h2>
<p>Add your NDS device photos here:</p>

<pre>
/assets/
   screenshot_menu.png
   screenshot_ananas.png
   screenshot_pasteque.png
</pre>

<hr>

<h2>Build & Run</h2>
<pre>
make
make run
</pre>

<hr>

<h2>Authors</h2>
<ul>
  <li><strong>TITOVA Xenia</strong></li>
  <li><strong>HAMMOUMI Abir</strong></li>
</ul>
