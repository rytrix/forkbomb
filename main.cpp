#include <cstdio>
#include <functional>
#include <random>
#include <thread>

// source https://giggeli.com/blogs/news/800-terms-for-the-penis
const char *names[] = {
    "Anaconda",
    "Antenna",
    "Appendage",
    "Armadillo",
    "Arrow",
    "Baby maker",
    "Baguette",
    "Bald Avenger",
    "Bald-headed giggle stick",
    "Bally Wacker",
    "Banana",
    "Banger",
    "Baseball bat",
    "Baton",
    "Bayonet",
    "Beast",
    "Beef bayonet",
    "Beef whistle",
    "Bellend",
    "Big boy",
    "Big guy",
    "Biscuit",
    "Bishop",
    "Black mamba",
    "Blastocyst",
    "Blood sausage",
    "Blue-veined custard chucker",
    "Blue-veined junket pumper",
    "Boaby",
    "Bobbin",
    "Bollocks",
    "Bologna pony",
    "Bolt",
    "Bone",
    "Boner",
    "Booboo",
    "Boom stick",
    "Boot",
    "Bopper",
    "Botswana beef bayonet",
    "Bouncer",
    "Bouncing Betty",
    "Braciole",
    "Brain",
    "Branch",
    "Bratwurst",
    "Broccoli",
    "Broccoli spear",
    "Brown trout",
    "Brownie",
    "Brutus and the Twins",
    "Bubble",
    "Bubble gum machine",
    "Buckaroo",
    "Buckwheat",
    "Buddah\'s belly button",
    "Buffalo soldier",
    "Bulge",
    "Bull",
    "Bull\'s-eye",
    "Bully beef",
    "Bully stick",
    "Bum tickler",
    "Bumper",
    "Burrito",
    "Buster",
    "Butt dart",
    "Butterbean",
    "Button",
    "Caber",
    "Cabeza",
    "Cactus",
    "Cadbury\'s c",
    "Cajones",
    "Camel toe",
    "Cane",
    "Cannoli",
    "Captain winky",
    "Capuchin",
    "Carrot",
    "Cervix sentinel",
    "Chameleon",
    "Champignon",
    "Cheese log",
    "Cheesestick",
    "Chef\'s special",
    "Cherub",
    "Chicken",
    "Chico stick",
    "Choad",
    "Chode",
    "Chopper",
    "Chowder",
    "Christmas goose",
    "Chub",
    "Chubby",
    "Chuck Dickens",
    "Cigar",
    "Cinnamon roll",
    "Clam",
    "Classic",
    "Clit stick",
    "Cloak",
    "Clock",
    "Club",
    "Cobra",
    "Cock",
    "Cod",
    "Colossus",
    "Commander",
    "Cone",
    "Conga",
    "Conquistador",
    "Consolation prize",
    "Cookie",
    "Corkscrew",
    "Corn dog",
    "Cornholio",
    "Cornish game hen",
    "Corporal",
    "Cossack",
    "Cougar bait",
    "Coxcomb",
    "Crank",
    "Crankshaft",
    "Creamer",
    "Crimper",
    "Crimson mushroom",
    "Crinkle-cut",
    "Crown jewels",
    "Crunchwrap",
    "Crème de la crème",
    "Cucumber",
    "Cummerbund",
    "Custard launcher",
    "Cylinder",
    "D\'s",
    "Dagger",
    "Dallas Dangler",
    "Danger noodle",
    "Darth Vader",
    "Deep sea diver",
    "Dick",
    "Dickas Hilton",
    "Ding dong",
    "Ding-dong",
    "Dingaling",
    "Dipstick",
    "Disco stick",
    "Dismount",
    "Divining rod",
    "DJ",
    "Dog",
    "Doggy",
    "Dolly",
    "Dong",
    "Donkey",
    "Doorknob",
    "Dope stick",
    "Dork",
    "Dormouse",
    "Double barrel",
    "Double dragon",
    "Downstairs department",
    "Drainpipe",
    "Driller",
    "Drumstick",
    "Dude piston",
    "Dumb stick",
    "Dutch courage",
    "Dutch rudder",
    "Excalibur",
    "Firehose",
    "Franks and beans",
    "Gerald",
    "Gherkin",
    "Giggeli",
    "Goldfinger",
    "Groin",
    "Hammer",
    "hammer of love",
    "Hammer of Thor",
    "handle",
    "hard drive",
    "Hard-on",
    "hardware",
    "hatchet wound",
    "he-man",
    "heat-seeking missile",
    "heat-seeking moisture missile",
    "helmet",
    "herbie",
    "Hercules",
    "high hard one",
    "hoo-ha",
    "hoo-hoo",
    "hook",
    "horn",
    "Hose",
    "hose",
    "hot dog",
    "hot rod",
    "hot sausage",
    "Humphrey",
    "hymie",
    "iceberg",
    "Indiana Bones",
    "Jack in the box",
    "Jack\'s magic beanstalk",
    "Jackhammer",
    "jammy",
    "janitor in the hallway",
    "java",
    "javelin",
    "jawbreaker",
    "Jedi",
    "Jefferson",
    "jelly doughnut",
    "Jenny Craig",
    "Jerry",
    "jiffy stick",
    "Jimmy",
    "Jizz Launcher",
    "John Henry",
    "John Johnson",
    "Johnson",
    "Jorma",
    "Joy-stick",
    "Joystick",
    "joystick",
    "Judge",
    "Juicy fruit",
    "jumbo",
    "Jumper",
    "Junior",
    "Junk",
    "junk",
    "justin",
    "Justus",
    "Kaiser",
    "kebab",
    "Keck",
    "Kennedy",
    "kielbasa",
    "King Ding Dong",
    "King Kong",
    "King Richard",
    "King size",
    "King snake",
    "King\'s scepter",
    "King\'s sword",
    "Kipper",
    "Kitty",
    "Knob",
    "Knobgoblin",
    "Knobhead",
    "Knobkerrie",
    "Knobstick",
    "Kraken",
    "Krull the Warrior King",
    "Kulli",
    "Kyrpä",
    "L\'Engin",
    "L\'Outil",
    "L\'Unita",
    "Lady-pleaser",
    "Laidy\'s lollypop",
    "Lance",
    "Lancer",
    "Lava flow",
    "Leader",
    "Leaky faucet",
    "Leatherman",
    "Lechon",
    "Leek",
    "Leg",
    "Leg of lamb",
    "Leg of mutton",
    "Leggy",
    "Lemon",
    "Lemondrop",
    "Length",
    "Lengthy",
    "Leo",
    "Leosaurus",
    "Leper",
    "Leroy",
    "Leviathan",
    "Libido",
    "Lick",
    "Lickety-split",
    "Lighthouse",
    "Lightning rod",
    "Lil\' bro",
    "Lil\' willy",
    "Lily",
    "Lima",
    "Limber dick",
    "Limber jimmy",
    "Limbo",
    "Limousine",
    "Limp biscuit",
    "Limp noodle",
    "Limp penis",
    "Limp-dick",
    "Limp-jim",
    "Limpkin",
    "Lincoln",
    "Lindy",
    "Lingam",
    "Link",
    "Linty",
    "Lion",
    "Lipstick",
    "Liquidator",
    "Liquor stick",
    "Lissome",
    "Little birdie",
    "Little bro",
    "Little chap",
    "Little guy",
    "Little head",
    "Little john",
    "Little man",
    "Little peter",
    "Little soldier",
    "Little willy",
    "Lizard",
    "Lizard tongue",
    "Locomotive",
    "Log",
    "Lollipop",
    "Long Dong Silver",
    "Long dong silver",
    "Long fellow",
    "Long john",
    "Long johnson",
    "Long one",
    "Long stick",
    "Longfellow",
    "Longfellow diller",
    "Longhorn",
    "Longie",
    "Longjohn",
    "Longshanks",
    "Longstaff",
    "Magic Mike",
    "Magic stick",
    "Magic Wand",
    "Magic wand",
    "Manhood",
    "Meat Scepter",
    "Meat stick",
    "Member",
    "Micropenis",
    "Mini-me",
    "Missile",
    "Moby Dick",
    "Mojo",
    "Monster",
    "Mount Vesuvius",
    "Mr. Happy",
    "Mr. Winky",
    "Mule",
    "Mushroom",
    "Mushroom Head",
    "Mutton",
    "Myrtle",
    "Nard",
    "Nether rod",
    "One-eye Pete",
    "One-Eyed Monster",
    "One-eyed monster",
    "One-Eyed Snake",
    "One-eyed trouser snake",
    "One-eyed wonder weasel",
    "Organ",
    "Package",
    "Packer",
    "Packing heat",
    "Pecker",
    "Pee-Pee",
    "Pee-pee",
    "Peen",
    "Pencil",
    "Pencil dick",
    "Penile appendage",
    "Penile shaft",
    "Penile tissue",
    "Penile unit",
    "Penile weapon",
    "Penis",
    "Pepperoncini",
    "Peter",
    "Phallos",
    "Phallus",
    "Piece",
    "Pink Oboe",
    "Pintle",
    "Pipe",
    "Pistol",
    "Piston",
    "Pleasure Stick",
    "Plonker",
    "Pocket Rocket",
    "Pogo stick",
    "Poker",
    "Pole",
    "Popcorn",
    "Pork Sword",
    "Prick",
    "Private",
    "Private part",
    "Purple-headed yogurt slinger",
    "Purple-helmeted trouser snake",
    "Purple-Helmeted Warrior of Love",
    "Purple-helmeted warrior of love",
    "Purple-helmeted yogurt thrower",
    "Python",
    "Quiver bone",
    "Ramrod",
    "Ranger",
    "Rascal",
    "Red-capped mushroom",
    "Rod",
    "Root of Jesse",
    "Rude boy",
    "Sausage",
    "Scepter",
    "Schlong",
    "Schwanz",
    "Schwanzstucker",
    "Schwetty balls",
    "Scooby Snack",
    "Screwdriver",
    "Scrod",
    "Scrotum",
    "Sea monster",
    "Secret weapon",
    "Shaft",
    "Shillelagh",
    "Shiv",
    "Shlong",
    "Skin Flute",
    "Skin flute",
    "Skinner",
    "Slingblade",
    "Slug",
    "Slugger",
    "Smacker",
    "Snake",
    "Snapper",
    "Soldier",
    "Spam javelin",
    "Spear",
    "Speed Bump",
    "Speedboat",
    "Spigot",
    "Spigot of love",
    "Spitstick",
    "Spitter",
    "Sponge",
    "Spongebob",
    "Sprout",
    "Spunk gun",
    "Spurt gun",
    "Squirt gun",
    "Staff",
    "Stallion",
    "Stand",
    "Stand up",
    "Starfruit",
    "Stick",
    "Stiffie",
    "Stiffy",
    "Stinger",
    "Stock",
    "Stone",
    "Stone of David",
    "Stonehenge",
    "Stonker",
    "Stopper",
    "Striker",
    "Stud",
    "Stump",
    "Submarine",
    "Sugar stick",
    "Super soaker",
    "Supercock",
    "Surfboard",
    "Swamp lizard",
    "Swansong",
    "Sweetmeat",
    "Swiss Army Penis",
    "Swizzle stick",
    "Sword",
    "Tabasco",
    "Tadger",
    "Tail",
    "Tall tommy",
    "tally",
    "Tallywacker",
    "tallywhacker",
    "Tang",
    "Tank",
    "tapa",
    "Tassle",
    "Tasty pastry",
    "tater",
    "Tazmanian devil",
    "Tea and crumpets",
    "Tea stick",
    "Telescoping tower",
    "Tent peg",
    "Testicle",
    "Testicles",
    "testicular tissue",
    "testiculi",
    "testies",
    "testons",
    "testosterbone",
    "The anaconda",
    "The baton",
    "The big guy",
    "the big vein",
    "the bishop",
    "The blue-veined custard chucker",
    "The chopper",
    "The cone",
    "the conga",
    "The cyclops",
    "The ding dong",
    "The Dipstick",
    "The dong",
    "The driver",
    "The dude piston",
    "the eye of the needle",
    "the family jewels",
    "the flagpole",
    "The flesh flute",
    "The flesh rocket",
    "the fleshy tripod",
    "the fuck stick",
    "the fun rod",
    "The grower",
    "the head",
    "The heat-seeking moisture missile",
    "the hose",
    "The joystick",
    "the King",
    "The knob",
    "the little man in the boat",
    "The love muscle",
    "the magic wand",
    "the main vein",
    "The male member",
    "the man in the boat",
    "The meat whistle",
    "the member",
    "The middle leg",
    "The mighty mite",
    "the old boy",
    "The old man",
    "The one-eyed captain",
    "The one-eyed monster",
    "the one-eyed snake",
    "The one-eyed wonder worm",
    "The package",
    "The peen",
    "The peeper",
    "the pendulum",
    "the peter",
    "The pink cigar",
    "the pink oboe",
    "The pipe",
    "the piston",
    "the pleasure pole",
    "The poker",
    "The pole",
    "the pork sword",
    "the prick",
    "The purple-helmeted warrior",
    "the purple-helmeted warrior of love",
    "The python",
    "The rocket",
    "The rod",
    "The salami",
    "The sausage",
    "The schlong",
    "the scoop",
    "The shaft",
    "The shotgun",
    "The skin flute",
    "The snake",
    "the spitter",
    "the staff of life",
    "the stick",
    "The stiff one",
    "The stinger",
    "the stonker",
    "the sword",
    "The third leg",
    "The tool",
    "The trouser snake",
    "The tube steak",
    "the unit",
    "The wang",
    "the weasel",
    "The wedge",
    "the wee-wee",
    "The weenie",
    "The whopper",
    "The wiener",
    "The wiggle stick",
    "the willy",
    "the wingwang",
    "The womb raider",
    "The wonder worm",
    "The woody",
    "the worm",
    "thingy",
    "Third Leg",
    "Third leg",
    "Thorn",
    "Thrill drill",
    "Throb knob",
    "throbber",
    "Throbbing gristle",
    "Thumper",
    "Thunderbird",
    "Thunderbolt",
    "Thunderstick",
    "Tic Tac",
    "Tickle pickle",
    "Tickler",
    "Tiger",
    "Tiki",
    "Timber",
    "Time machine",
    "Tingler",
    "Tinker",
    "Tinkerbell",
    "tip",
    "Tip drill",
    "Tip of the iceberg",
    "Tipper",
    "Tissue",
    "Titan",
    "Toad",
    "toadstool",
    "todger",
    "Toe",
    "Tool",
    "tooly",
    "tooter",
    "Toothpick",
    "Tootsie roll",
    "Top gun",
    "Torch",
    "Tower",
    "Tower of power",
    "tractor beam",
    "Trafalgar",
    "Treasure",
    "Tree trunk",
    "Tri-pod",
    "Trinket",
    "Trombone",
    "Trouser Snake",
    "Trousersnake",
    "Trumpet",
    "Truncheon",
    "Trunk",
    "Tuba",
    "tube",
    "Tummy banana",
    "Tuna Can",
    "Tuna can",
    "Tuna torpedo",
    "Turgid Trouser Snake",
    "Turgid turtle",
    "turkey",
    "Turkey baster",
    "Turkey neck",
    "Turnip",
    "turtle",
    "Turtleneck",
    "Tusk",
    "twanger",
    "Twig",
    "Twig and Berries",
    "Twig and berries",
    "Twinkie",
    "twinky",
    "Twister",
    "Two ball cane",
    "Two veg and meat",
    "Two-legged Boa",
    "Two-legged tripod",
    "twonker",
    "Umbrella handle",
    "Uncircumcised wonder",
    "Uncle",
    "Uncle Dick",
    "Uncle John",
    "Unit",
    "unmentionables",
    "Uzi",
    "Vainilla",
    "Vainilla Stick",
    "Valiant vein",
    "Veggie",
    "vein",
    "Vein train",
    "Vein train.",
    "Vein-cutter",
    "Vein-erect",
    "Veined custard launcher",
    "VeinMaster 3000",
    "Veiny Victor",
    "Veinzilla",
    "Velvet sword",
    "Vessel",
    "Vienna Sausage",
    "Viking horn",
    "Viking Staff",
    "Vindicator",
    "Vinegar",
    "Violin",
    "Virility",
    "Vixen",
    "Vodka",
    "Volcano",
    "Wally",
    "Wand",
    "wand of light",
    "Wang",
    "wang dang doodle",
    "Wanger",
    "wangle",
    "Wangsta",
    "Wanker",
    "wankie",
    "War club",
    "Warrior",
    "Weapon",
    "Weapon of ass destruction",
    "Weapon of mass destruction",
    "Weapon of Mass Seduction",
    "Wedge",
    "Wee-wee",
    "weenie",
    "weewee",
    "Weiner",
    "wenis",
    "wet noodle",
    "Whacker",
    "Whammer",
    "Whang",
    "Whangdoodle",
    "wheenie",
    "Whip",
    "Whistle",
    "White gold",
    "White Mamba",
    "Whoopie Stick",
    "whopper jr.",
    "widget",
    "Wiener",
    "Wiener Schnitzel",
    "Wiggle stick",
    "wiggle worm",
    "Wiggler",
    "Wiggly",
    "William",
    "Willow",
    "Willpower",
    "Willy",
    "Willy the one-eyed wonder worm",
    "willy wonka",
    "Wing wong",
    "wing-wang",
    "Wingman",
    "Winkie",
    "Winky",
    "Winnebago",
    "Winner",
    "Winston",
    "Winston Churchill",
    "Wintermelon",
    "Wisdom Wand",
    "Wise man",
    "Wishbone",
    "wizard sleeve",
    "Wonder Worm",
    "Wood",
    "Woodpecker",
    "Woody",
    "Worm",
    "Wormhole",
    "wormy",
    "Wrecking ball",
    "Wriggler",
    "Wriggly",
    "Wrinkle",
    "wrinklepump",
    "Wrist Rocket",
    "Wyvern",
    "X-factor",
    "Xylophone",
    "Yad",
    "Yak",
    "Yam",
    "yam",
    "Yam bag",
    "Yams",
    "Yang",
    "Yankee doodle",
    "Yard",
    "Yardstick",
    "Yawing Yowie",
    "Yearling",
    "Yellow",
    "Yellow Belly",
    "Yellow Dart",
    "Yellow dragon",
    "Yellow Peril",
    "Yellow Sausage",
    "Yellow submarine",
    "Yen",
    "Yew",
    "Ygdrasil\'s staff",
    "Yin-yang serpent",
    "yingyang",
    "Yippie",
    "Yipsicle",
    "Yo-yo",
    "Yob",
    "yobbo",
    "Yoda",
    "Yoga stick",
    "Yoghurt Cannon",
    "Yoghurt gun",
    "Yoghurt pistol",
    "Yogurt",
    "Yogurt hose",
    "Yogurt Slinger",
    "Yogurt slinger",
    "Yogurt thrower",
    "Yolk",
    "Yolkstick",
    "Yolky poke",
    "Yoni",
    "yoni stick",
    "Youth",
    "Yoyo",
    "Yuca",
    "Yule log",
    "Yum yum",
    "Yum-yum",
    "Yummy",
    "Zapper",
    "Zealot",
    "Zebedee",
    "Zebracorn horn",
    "zebu",
    "Zen",
    "Zephyr",
    "Zeppelin",
    "Zesty Italian",
    "Zeus",
    "ziggurat",
    "Zigzag",
    "Zilla",
    "Zinger",
    "Zipper",
    "Zipper Ripper",
    "Zipper snake",
    "Zippy",
    "ziz",
    "Zog",
    "zombie",
    "Zombie maker",
    "Zombie stick",
    "Zonker",
    "Zoom Stick",
    "Zoombini",
    "Zoomer",
    "Zoot stick",
    "Zorro",
    "Zucchini",
    "Zygmunt Freud",
    "Zygote poker",
    "Zygotene",
};

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0, 893);
auto dice = std::bind(distribution, generator);

void penis() {
  auto index = dice();
  printf("%s\n", names[index]);
  std::thread t(penis);
  penis();
  t.join();
}

int main() {
  penis();
  return 0;
}
