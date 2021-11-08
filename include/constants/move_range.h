#ifndef GUARD_CONSTANTS_MOVE_RANGE_H
#define GUARD_CONSTANTS_MOVE_RANGE_H


/*
 *  From Anon... Each move in each move category
 *
 *   b'00': ['None']
 *   b'01': ['Wide Slash']
 *   b'02': ['Blast Burn', 'Cut', 'Lovely Kiss', 'Night Shade', 'Overheat', 'Sleep Powder', 'Stun Spore', 'Thunderbolt']
 *   b'03': ['Acid', 'Air Cutter', 'Attract', 'Barrage', 'Blizzard', 'Bone Rush', 'Decoy Maker', 'Destiny Bond', 'Dragon Rage', 'Egg Bomb', 'Ember', 'Eruption', 'Fire Blast', 'Flame Wheel', 'Frenzy Plant', 'Grasswhistle', 'Hyper Voice', 'Hypnosis', 'Ice Ball', 'Icicle Spear', 'Itemize', 'Leech Seed', 'Magical Leaf', 'Megahorn', 'Metal Sound', 'Mist Ball', 'Mud Shot', 'Mud-Slap', 'Observer', 'Poison Sting', 'Present', 'Rock Blast', 'Sand-Attack', 'Screech', 'Sing', 'Sludge', 'Smokescreen', 'Spider Web', 'Stay Away', 'Supersonic', 'Swift', 'Transfer', 'Tri Attack', 'Water Gun', 'Will-O-Wisp']
 *   b'04': ['Beat Up', 'Morning Sun', 'Wild Call']
 *   b'05': ['Milk Drink', 'Moonlight']
 *   b'06': ['HP Gauge', 'Hail', 'Mud Sport', 'Rain Dance', 'Sandstorm', 'Sunny Day', 'Teeter Dance', 'Water Sport']
 *   b'07': ['Perish Song']
 *   b'09': ['Spin Slash']
 *   b'0a': ['Assist', 'Cleanse', 'Curse', 'Escape', 'Item-Toss', 'Metronome', 'Nature Power', 'Pounce', 'Projectile', 'Sleep Talk', 'Snore', 'Trapper']
 *   b'0b': ['Absorb', 'Aerial Ace', 'Ancientpower', 'Arm Thrust', 'Astonish', 'Bide 2', 'Bind', 'Bite', 'Blaze Kick', 'Block', 'Body Slam', 'Bone Club', 'Brick Break', 'Charm', 'Clamp', 'Comet Punch', 'Confuse Ray', 'Confusion', 'Constrict', 'Cotton Spore', 'Covet', 'Crabhammer', 'Cross Chop', 'Crunch', 'Crush Claw', 'Disable', 'Dizzy Punch', 'Double Kick', 'Double-Edge', 'Doubleslap', 'Dragon Claw', 'Dream Eater', 'Drill Peck', 'Dynamicpunch', 'Echo', 'Encore', 'Endeavor', 'Extrasensory', 'Facade', 'Faint Attack', 'Fake Tears', 'False Swipe', 'Featherdance', 'Fire Punch', 'Fire Spin', 'Fissure', 'Flail', 'Flash', 'Flatter', 'Foresight', 'Frustration', 'Fury Attack', 'Fury Cutter', 'Fury Swipes', 'Giga Drain', 'Glare', 'Guillotine', 'Gust', 'Headbutt', 'Hi Jump Kick', 'Hidden Power', 'Horn Attack', 'Horn Drill', 'Hurl', 'Hyper Fang', 'Ice Punch', 'Imprison', 'Iron Tail', 'Is watching', 'Jump Kick', 'Karate Chop', 'Kinesis', 'Knock Off', 'Leaf Blade', 'Leech Life', 'Leer', 'Lick', 'Low Kick', 'Luster Purge', 'Mean Look', 'Mega Drain', 'Mega Kick', 'Mega Punch', 'Metal Claw', 'Mimic', 'Muddy Water', 'Needle Arm', 'Nightmare', 'No-Move', 'One-Shot', 'Outrage', 'Pain Split', 'Pay Day', 'Peck', 'Petal Dance', 'Poison Fang', 'Poison Gas', 'Poison Tail', 'Poisonpowder', 'Possess', 'Pound', 'Psychic', 'Psycho Boost', 'Rapid Spin', 'Regular attack', 'Return', 'Reversal', 'Roar', 'Rock Slide', 'Rock Throw', 'Rock Tomb', 'Role Play', 'Rolling Kick', 'Rollout', 'Sacred Fire', 'Sand Tomb', 'Scary Face', 'Scratch', 'Secret Power', 'Seismic Toss', 'Shadow Punch', 'Sheer Cold', 'Shocker', 'Sketch', 'Skill Swap', 'Sky Uppercut', 'Slam', 'Slash', 'Smellingsalt', 'Smog', 'Spark', 'Spit Up', 'Spite', 'Steel Wing', 'Stomp', 'Strength', 'Struggle', 'Submission', 'Super Fang', 'Superpower', 'Surf', 'Swagger', 'Sweet Kiss', 'Tackle', 'Tail Whip', 'Take Down', 'Takeaway', 'Taunt', 'Thief', 'Thunder', 'Thunder Wave', 'Thunderpunch', 'Thundershock', 'Tickle', 'Torment', 'Toxic', 'Trick', 'Triple Kick', 'Twister', 'Vicegrip', 'Vine Whip', 'Water Spout', 'Waterfall', 'Whirlpool', 'Whirlwind', 'Wing Attack', 'Wrap', 'Yawn']
 *   b'0c': ['Thrash']
 *   b'0d': ['Bloop Slash', 'Extremespeed', 'Fake Out', 'Mach Punch', 'Quick Attack']
 *   b'0e': ['Aeroblast', 'Aurora Beam', 'Blowback', 'Bonemerang', 'Bubble', 'Bubblebeam', 'Bullet Seed', 'Dragonbreath', 'Flamethrower', 'Hydro Cannon', 'Hydro Pump', 'Hyper Beam', 'Ice Beam', 'Icy Wind', 'Meteor Mash', 'Octazooka', 'Pin Missile', 'Psybeam', 'Psywave', 'Razor Leaf', 'Shadow Ball', 'Shock Wave', 'Signal Beam', 'Sludge Bomb', 'Sonicboom', 'Spike Cannon', 'String Shot', 'Switcher', 'Twineedle', 'Volt Tackle', 'Water Pulse', 'Weather Ball', 'Zap Cannon']
 *   b'0f': ['Famish', 'Growl', 'Heat Wave', 'Memento', 'Odor Sleuth', 'Petrify', 'Powder Snow', 'Siesta', 'Silver Wind', 'Slow Down', 'Spore', 'Sweet Scent', 'Totter', 'Two-Edge', 'Vacuum-Cut', 'Warp']
 *   b'10': ['Agility', 'Aromatherapy', 'Heal Bell', 'Refresh', 'Safeguard', 'Softboiled', 'Speed Boost', 'Uproar']
 *   b'11': ['Baton Pass', 'Haze']
 *   b'12': ['Earthquake', 'Magnitude']
 *   b'13': ['$$$', '$$$', 'Acid Armor', 'Amnesia', 'Barrier', 'Belly Drum', 'Bide', 'Bulk Up', 'Calm Mind', 'Camouflage', 'Conversion', 'Conversion 2', 'Cosmic Power', 'Counter', 'Defense Curl', 'Detect', 'Doom Desire', 'Double Team', 'Dragon Dance', 'Endure', 'Excavate', 'Focus Energy', 'Follow Me', 'Future Sight', 'Growth', 'Grudge', 'Harden', 'Howl', 'Ingrain', 'Invisify', 'Iron Defense', 'Light Screen', 'Lock-On', 'Long Toss', 'Magic Coat', 'Meditate', 'Mind Reader', 'Minimize', 'Mirror Coat', 'Mirror Move', 'Mist', 'Mobile', 'Pierce', 'Power-Ears', 'Protect', 'Pursuit', 'Rage', 'Rebound', 'Recover', 'Reflect', 'Rest', 'Revenge', 'Reviver', 'Scan', 'Searchlight', 'See Stairs', 'See-Trap', 'Sharpen', 'Slack Off', 'Snatch', 'Splash', 'Stockpile', 'Swords Dance', 'Tail Glow', 'Teleport', 'Transform', 'Trawl', 'Vital Throw', 'Wish', 'Withdraw', '[M:D1]', '[M:D1]']
 *   b'14': ['Bounce', 'Charge', 'Dig', 'Dive', 'Fly', 'Focus Punch', 'Skull Bash']
 *   b'15': ['Swallow', 'Synthesis']
 *   b'16': ['Helping Hand']
 *   b'17': ['Recycle']
 *   b'18': ['Spikes']
 *   b'19': ['Rock Smash']
 *   b'1a': ['Selfdestruct']
 *   b'1b': ['Explosion']
 *   b'1c': ['Razor Wind', 'Sky Attack', 'Solarbeam']
 *   b'1d': ['Drought', 'Fill-In', 'One-Room', 'Trap Buster']
 *   b'1e': ['Psych Up', 'Substitute']
 * */

#define MOVE_RANGE_NONE                   0
#define MOVE_RANGE_FACE_TILE_AND_2_FLANK  1
#define MOVE_RANGE_ALL_ENEMY_1_TILE       2
#define MOVE_RANGE_ENEMY_FRONT_CUT_CORNER 3
#define MOVE_RANGE_ALL_ALLIES_FLOOR       4
#define MOVE_RANGE_USER_ALL_ALLIES_FLOOR  5
#define MOVE_RANGE_ALL_POKEMON_FLOOR 6
#define MOVE_RANGE_ALL_ENEMY_FLOOR 7
#define MOVE_RANGE_NONE 9
#define MOVE_RANGE_NONE 0xA
#define MOVE_RANGE_NONE 0xB
#define MOVE_RANGE_NONE 0xC
#define MOVE_RANGE_NONE 0xD
#define MOVE_RANGE_NONE 0xE
#define MOVE_RANGE_NONE 0xF
#define MOVE_RANGE_NONE 0x10
#define MOVE_RANGE_NONE 0x11
#define MOVE_RANGE_NONE 0x12
#define MOVE_RANGE_NONE 0x13
#define MOVE_RANGE_NONE 0x14
#define MOVE_RANGE_NONE 0x15
#define MOVE_RANGE_ALLIES_ROOM_2 0x16 // used by Helping Hand
#define MOVE_RANGE_ALL_TMS_IN_BAG 0x17 // used by Recycle
#define MOVE_RANGE_NONE 0x18
#define MOVE_RANGE_WALL_IN_FRONT 0x19
#define MOVE_RANGE_NONE 0x1A
#define MOVE_RANGE_NONE 0x1B
#define MOVE_RANGE_NONE 0x1C
#define MOVE_RANGE_ORB_USER 0x1D
#define MOVE_RANGE_FACING_POKEMON 0x1E

#endif // GUARD_CONSTANTS_MOVE_RANGE_H 
