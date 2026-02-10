// MIT License
//
// Copyright (c) 2026 Code Life
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Southern Sayings
//     by Code Life
//     command line version using modern C++
//     version 1.4 - 2/3/2026
//     version 1.5 - 2/7/2026 - new option --polite to exclude sayings that aren't suitable for polite company
//     version 1.6 - 2/10/2026 - new option and sayings added
// Description: A collection of Southern sayings with their meanings.

#include <array>
#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

struct Saying {
    bool okForPoliteCompany; // default to true, but can be set to false for sayings that are not suitable for polite company
    string text;
    string meaning;
};

const vector<Saying> southernSayings = {
    {true,"Hotter than a billy goat in a pepper patch", "It's unbearably hot and almost comically so"},
    {true,"Colder than a well digger's behind in January", "It's freezing cold, often used during a sharp winter morning"},
    {true,"It's so hot the hens are laying hard-boiled eggs", "A funny way to exaggerate the high temperature"},
    {true,"It's raining like a cow peeing on a flat rock", "Describes a sudden heavy rain with a splashy and chaotic feel"},
    {true,"Hotter than blue blazes", "Describes extremely hot and hellish southern heat"},
    {true,"So humid, I could wring out the air", "Describes the sticky, muggy humidity"},
    {true,"The devil's beating his wife", "The sun is shining while it is raining at the same time."},
    {true,"Sweatin' like a sinner in church", "Used when someone is uncomfortably hot or nervous"},
    {true,"Don't know him from Adam's house cat", "Describing a stranger"},
    {true,"Feels like the Lord left the oven door open", "Used when the weather is oppressively hot and dry"},
    {true,"About as useful as a screen door on a submarine", "A humorous way to say someone seems useless"},
    {true,"He's got more nerve than a bum tooth", "Describes someone who is bold or has no shame"},
    {true,"She could start an argument in an empty house", "A drama stirrer or someone always picking a fight"},
    {true,"He's slicker than a greased pig at a county fair", "Someone who's cunning or hard to catch figuratively"},
    {true,"Prettier than a speckled pup under a red wagon", "Means someone is absolutely adorable and attractive"},
    {true,"Dumber than a bag of hammers", "Used to call someone foolish or unintelligent"},
    {true,"Fixin' to", "This person is about to do something."},
    {true,"Lower than a snake's belly in a ditch", "Refers to someone with no moral backbone"},
    {true,"Got a face for radio", "A backhanded way of saying someone isn't very photogenic"},
    {true,"Crazier than a sprayed roach", "Someone acting wildly or irrationally - also you may hear 'crazier than a betsy bug'"},
    {true,"Lazy as a hound dog on a porch swing", "Extremely lazy and content to stay idle"},
    {true,"Wouldn't hit a lick at a snake", "Describes someone who won't even make a slight effort"},
    {true,"Too lazy to scratch an itch", "Someone who refuses to do even basic tasks"},
    {true,"Rather climb a tree to tell a lie than stand on the ground and tell the truth", "A twist on laziness with deception added in"},
    {true,"Moves slower than molasses in January", "Someone who takes his sweet time, and drags his feet!"},
    {true,"Can't be bothered unless there's gravy involved", "Only works if there's a personal payoff"},
    {true,"So lazy he'd rather sleep standing up than find a place to lie down", "Comically exaggerates someone's unwillingness to make effort"},
    {true,"If work was a fire, he'd freeze to death", "A jab at someone who avoids work at all costs"},
    {true,"Got a Ph.D. in doing nothing", "Humorous way to label someone professionally lazy"},
    {true,"Lazier than a toad on a lily pad", "Slow and stationary, just soaking up life"},
    {true,"He's a few fries short of a Happy Meal", "Not very bright or lacking common sense"},
    {true,"If brains were leather, he wouldn't have enough to saddle a June bug", "Extremely unintelligent"},
    {true,"The porch light's on, but nobody's home", "Someone looks alert but isn't really mentally present"},
    {true,"Sharp as a mashed potato sandwich", "A humorous insult for someone lacking intellect"},
    {true,"One biscuit shy of a breakfast", "A subtle, funny way to say someone's a bit off mentally"},
    {true,"Couldn't pour water out of a boot with instructions on the heel", "Someone who's totally clueless"},
    {true,"Not the brightest crayon in the box", "Lacks intelligence or awareness"},
    {true,"If ignorance was bliss, he'd be the happiest man alive", "Extremely uninformed or naive"},
    {true,"Got the IQ of a pinecone", "Sarcastic way to say someone is intellectually lacking"},
    {true,"Dumber than dirt", "Simple, blunt, and classic southern jab"},
    {true,"Tighter than bark on a tree when it comes to money", "Very frugal or stingy"},
    {true,"Been rode hard and put up wet", "Someone who looks worn out or rough around the edges"},
    {true,"Family trees in some parts don't fork", "A joke about inbreeding or lack of diversity in relationships"},
    {true,"Nuttier than a fruitcake", "Used to describe an eccentric or unpredictable person"},
    {true,"That boy's momma didn't raise no fool", "A way to say someone's smart or knows better"},
    {true,"She's as high-maintenance as a show pony", "A partner or relative who requires a lot of attention"},
    {true,"He's married, but the fence still has a few holes in it", "Suggesting infidelity or lack of commitment"},
    {true,"Kin to everybody and nobody at the same time", "Refers to someone who claims lots of relations, often loose ones"},
    {true,"Got more baggage than Atlanta airport", "Someone who comes with a lot of emotional history and drama"},
    {true,"More whipped than a bowl of mashed potatoes", "Someone overly submissive in a relationship"},
    {true,"Nervous as a long-tailed cat in a room full of rocking chairs", "Extremely anxious or jumpy"},
    {true,"Happy as a pig in slop", "Completely content and satisfied"},
    {true,"Busy as a one-legged cat in a sandbox", "Overwhelmed or trying hard to manage a lot."},
    {true,"Crooked as a dog's hind leg", "Refers to someone dishonest or shady"},
    {true,"Uglier than a mud fence after a rainstorm", "A brutal way to call someone unattractive"},
    {true,"Like herding cats", "Trying to control a chaotic or unmanageable situation"},
    {true,"Like a possum playin' dead", "Avoids problems or pretends not to notice them"},
    {true,"Meaner than a skillet full of rattlesnakes", "Describes someone especially vicious or angry"},
    {true,"More tricks than a squirrel in a corn crib", "Someone who's clever or sneaky"},
    {true,"Runnin' around like a chicken with its head cut off", "Acting frantic or disorganized in an inefficient way"},
    {true,"Between a rock and a hard place", "Stuck in a situation where there are no good choices"},
    {true,"If it were raining soup, I'd get hit with a fork.", "Nothing ever goes right for this person"},
    {true,"Tougher than a two-dollar steak", "Describes something or someone extremely resilient or hard to handle"},
    {true,"I'm hanging on by a thread", "Barely managing to hold it together - mentally, emotionally, or financially"},
    {true,"This ain't my first rodeo", "A way to say you've been through hard times before or done this enough to be familiar with it"},
    {true,"That dog won't hunt", "The plan or idea won't work"},
    {true,"Up a creek without a paddle", "In a bad situation with no clear way out"},
    {true,"Tighter than Dick's hatband", "Extremely cheap or stingy or strange"},
    {true,"That man squeezes a penny so hard, Abe Lincoln cries", "A vivid exaggeration of frugality"},
    {true,"She's got champagne taste on a beer budget", "Loves expensive things but can't afford them"},
    {true,"He works harder than a one-eyed dog in a smokehouse", "Someone who works extremely hard"},
    {true,"Got more money than sense", "Rich, but lacking good judgment"},
    {true,"Wouldn't give you the time of day unless it made him a nickel", "Very self-serving or greedy"},
    {true,"Busier than a termite in a sawmill", "Incredibly busy or industrious"},
    {true,"Spends money like it's going out of style", "Carelessly extravagant with money"},
    {true,"Tighter than a new pair of boots", "Can describe both stinginess and discomfort in spending"},
    {true,"Bless your heart", "Could be sympathy or a subtle way of calling you an idiot"},
    {true,"She's got a good personality", "Code for someone who isn't physically attractive"},
    {true,"He's not the sharpest knife in the drawer", "A gentle way of saying someone isn't intelligent"},
    {true,"Well, that's one way to do it", "Passive-aggressive disapproval masked as openness"},
    {true,"He means well", "Someone who tries but often fails or messes things up"},
    {true,"She's a handful!", "A polite way of saying someone's difficult and/or dramatic, and might include the word real in front of handful"},
    {true,"He could eat corn through a picket fence", "Describes someone with gapped teeth"},
    {true,"Beats all I've ever seen", "That tops everything. Variations: beats all I ever did see, beats all, that beats all"},
    {true,"You'd have to water that idea for it to grow", "A humorous way of calling it a dumb idea"},
    {true,"She's a real peach, with a pit", "She seems sweet but she has a mean streak"},
    {true,"He's slicker than owl snot", "Describes someone charming and maybe too much so"},
    {true,"She's sweeter than a June bug on a honeysuckle vine", "An adorable person with great behavior"},
    {true,"He's been bit by the love bug", "Clearly smitten or falling in love"},
    {true,"She put a spell on him stronger than grandma's moonshine", "Deeply infatuated and under someone's charm"},
    {true,"He's more whipped than mashed taters at a church supper", "Comically devoted or overly obedient in a relationship"},
    {true,"She could charm the socks off a rooster", "Very flirtatious"},
    {true,"Well, I'll be?", "Expressing pure and wide-eyed astonishment"},
    {true,"I'll be derned", "Expression of surprise"},
    {true,"Possum in a rosebush!", "Expression of surprise"},
    {true,"Would argue with a fence post", "This describes someone very argumentative, so much they would argue with an inanimate object."},
    {true,"Like a hair on a biscuit", "Describes someone who is annoying or out of place"},
    {true,"We're living in high cotton", "Experiencing a time of well being"},
    {true,"What's got you all cattywampus?", "Askew, disordered, or crooked"},
    {true,"He was three sheets to the wind", "He was intoxicated"},
    {true,"It's over yonder", "A general direction, not a specific place, and it might not be within reach but generally within sight"},
    {true,"He's having a hissy fit", "An adult having a full melt down and emotional outburst"},
    {true,"Quit bein' ugly", "This has nothing to do with looks - stop being mean, rude, or acting uncouth"},
    {true,"That doesn't amount to a hill of beans", "Something of little importance or value"},
    {true,"Lord willing and if the creeks don't rise", "A phrase that means if everything goes according to plan and likely originated from early 19th century travelers who had to cross creeks"},
    {true,"He's silly as all get out", "Utmost silliness"},
    {true,"If I had my druthers", "If I had my choice"},
    {true,"I'm finer than frog hair and not half as slick", "A funny response to 'How are you?'"},
    {true,"Don't try to plow through the stump", "Farm wisdom about choosing the wiser path instead of the hardest one"},
    {true,"He was plumb tuckered out", "Extremely tired or exhausted - Plumb may be a general intensifier word using in other sayings"},
    {true,"You can catch more flies with honey than with vinegar", "A proverb about the power of persuasion sometimes used when someone is being 'ugly' in the southern sense"},
    {true,"She thinks she's so high falutin'", "Very pretentious"},
    {true,"Coke", "Not just referring to Coca-Cola but any carbonated soda"},
    {true,"Too big for his britches", "Someone obviously full of themselves"},
    {true,"Blowin' up a storm", "You may hear a Southerner say this when the wind picks up and the skies get cloudy."},
    {true,"I'm so full, I'm about to pop", "What you might hear from a Southerner after a hearty meal"},
    {true,"Y'all", "a common Southern phrase as you and all squished together - but don't confuse it with \"all y'all\" which is a group larger than two people"},
    {true,"He thinks the sun comes up just to hear him crow.", "Conceited"},
    {true,"Til the cows come home", "Cows tend to take their time, so this means it could be all day or a long time at least"},
    {true,"Doohickey", "When a Southerner can't think of a particular name for something, it suddenly becomes a doohickey."},
    {true,"Cornbread ain't done in the middle", "Describes someone who is \"off\" in some way"},
    {true,"Fair is a place where pigs get judged", "This is used when you have to tell someone that life isn't always fair. 4H competitions at County and State Fairs are common throughout the South."},
    {true,"Tore up", "A person who is truly upset by something"},
    {true,"Don't have a dog in this fight", "This is heard from a Southerner who doesn't care one way or the other about the matter at hand."},
    {true,"A month of Sundays", "A very long time. It might be in reference to something like not visiting your mom for a while."},
    {true,"Piddlin'", "A piddlin' is a small amount that's not worth bothering with. Someone who is piddlin' in the yard is wasting time and not doing much."},
    {true,"Gimme some sugar", "What Grandma says when you pull in the driveway, pop out of the car, and come running. She's not looking for sweets; she wants a hug and a kiss."},
    {true,"Well, I declare!", "A Southerner using this phrase could be declaring any number of things: surprise, dissent, happiness. The only requirement is that you declare it loud and proud."},
    {true,"Hush your mouth", "A Southerner might use this to tell someone to stop complaining or to be quiet. It's also used to tell someone to stop being a baby."},
    {true,"I'll tell you what", "This is a point of emphasis and exclamation that often ends without any additional telling at all. It can also be the opening to striking a bargain, sharing a strongly held opinion, or offering a piece of advice you may or may not want to hear."},
    {true,"I reckon", "This can mean -- I suppose, I think, or I imagine. It is a quintessential Southern phrase, said by friends and family on porches and in rocking chairs all across the South."},
    {true,"It'll make ya wanna slap your mama", "Used to describe something that's so good that you might do something unthinkable or extreme as a result. It's often used to describe food that's insanely delicious."},
    {true,"A rooster one day and a feather duster the next", "This is a Southerner's creative way of saying that you shouldn't crow like a rooster about your wealth and belonging today, because it could all disappear tomorrow."},
    {true,"He ain't got the sense God gave a goose", "This is another nice way to say that someone is lacking in brain power."},
    {true,"Pretty is as pretty does", "Similar to the phrase 'quit being ugly,' this one alludes to what's on the inside, not the outside, that matters. The expression is a simple reminder, often given to children, to remind them to be kind to others and mind their manners."},
    {true,"Can't never could", "This is positive thinking, Southern style."},
    {true,"Preachin' to the choir", "something to quit doing when trying to convince someone who already agrees with you"},
    {true,"It'll all come out in the wash", "Like dirt and stains, worries and problems will wash away. Whatever is bothering you isn't serious, and it will eventually be resolved with no lasting effects and that means don't worry."},
    {true,"You can't make a silk purse out of a sow's ear", "No matter how hard you try, you just can't make something pretty out of something ugly."},
    {true,"It's raining cats and dogs!", "This means that it's a downpour and not that kittens and puppies are literally falling from the sky."},
    {true,"Aren't you precious?", "Likely full of sarcasm, unless directed toward an adorable child"},
    {true,"You're barking up the wrong tree.", "When you're very much in the wrong, you might hear this phrase. Another way this can be used is if someone is telling you to back off."},
    {true,"Hold your horses.", "This means to stop what you're doing, or to calm down."},
    {true,"Who licked the red off your candy?", "asked when there is a wondering why the person is so upset"},
    {true,"My eyeballs are floating!", "When you want to express just how badly you need the restroom, but you don't want to say it, use this phrase instead!"},
    {true,"She's madder than a wet hen.", "Someone is very angry and may need some time to cool down."},
    {false,"I been running all over hell's half acre.", "When your day has ended up with the Southerner going to many more places than he originally wanted or planned, you might hear this."},
    {true,"She's got a mind like a steel trap, but it's rusted shut", "Intelligence doesn't matter if you're unwilling to use it"},
    {false,"She's busier than a cat covering poop on a marble floor", "Don't mistake motion for progress"},
    {true,"Don't go to the devil for advice on how to fight temptation", "Be mindful of where you seek guidance and wisdom."},
    {true,"She's happier than a pig in a sunflower patch", "Appreciate the simple joys in life"},
    {true,"He's running like a scalded dog", "Sometimes urgency is the best motivator"},
    {true,"That'll jar your preserves", "Be ready for unexpected surprises in life"},
    {true,"He's as lost as last year's Easter egg", "Keep track of what matters or you might lose it"},
    {true,"She's sweeter than tea with a double dose of sugar", "Kindness never goes out of style"},
    {true,"Jumpy as a frog on a hot skillet", "Try to learn to stay calm under pressure"},
    {true,"She's like a hen trying to crow", "Stay true to who you are, not who others want you to be"},
    {true,"If it ain't broke, don't fix it", "Sometimes, simplicity is best"},
    {true,"Diggin' a hole deeper than a gopher on double time", "Know when to stop making things worse. (also, faster than a gopher in springtime)"},
    {true,"He's got more excuses than a dog has fleas", "Own your mistakes and don't try to justify them."},
    {true,"He's as stubborn as a mule in a mud pit", "Flexibility is key to success."},
    {true,"She's holdin' on tighter than a tick on a hound", "Know when to let go of things that no longer serve you."},
    {true,"He's walkin' on thin ice in cowboy boots", "Be careful where you tread. However, sometimes, the best decisions are the ones that come with the most risk."},
    {true,"She's spreadin' gossip faster than butter on a hot biscuit", "Guard your words as they can travel swiftly."},
    {true,"That idea's about as good as a screen door on a tornado shelter", "Think things through before acting on it"},
    {true,"Don't let the tail wag the dog", "Keep control of your priorities"},
    {true,"He's like a one-legged man in a butt-kicking contest", "Don't take on more than you can handle"},
    {true,"You can't make chicken salad out of chicken scratch", "Use quality resources for quality outcomes"},
    {true,"He's as unpredictable as a bull in a china shop", "Be mindful of how your actions may impact others"},
    {true,"She's shining brighter than a new penny in sunlight", "Confidence is an accessory to success"},
    {true,"She's got a heart bigger than the state of Texas", "Generosity enriches lives and strengthens communities"},
    {true,"She's like a firecracker on the Fourth of July", "Enthusiasm and energy are contagious"},
    {true,"That's a tough row to hoe", "Hard work pays off, but be prepared for challenges along the way."},
    {true,"Tarnation", "some believe this could be a mixture of eternal and damnation. This is usually said like, \"What in tarnation?\" as being shocked by something to get you agitated about."},
    {true,"Hankering", "This means getting a strong desire for something like fried chicken."},
    {true,"Fair to middlin'", "This means doing all right, but not too good or bad - just in the middle"},
    {true,"Ugly as sin", "This is something rather unsightly or unpleasant"},
    {true,"Fit as a fiddle", "In good health and spirits"},
    {true,"Knee-high to a grasshopper", "This is a hyperbolic expression meaning very young, as in I haven't seen him since he was knee-high to a grasshopper."},
    {true,"Happy as a lark", "This is someone or something that is very happy and carefree."},
    {false,"Drunker than Cooter Brown", "This was a real person who lived along the Mason-Dixon line during the civil war. As the years went by, Cooter Brown's reputation grew, and his name became synonymous with someone who was always inebriated."},
    {true,"Clean as a whistle", "Someone who is innocent or something is entirely clean and dirt-free, judging from its appearance"},
    {true,"Scarce as hen's teeth", "This is something very rare or difficult to find. Hens do not have teeth."},
    {true,"She's got more nerve than Carter's got liver pills", "Carters Products started as a pill-peddling company in the 19th century. Carters repped its \"Little Liver Pills\" so hard a Southern saying spawned from the advertisements. Alas, the Federal Trade Commission forced the drug-group to drop the \"liver\" portion of the ad, claiming it was deceptive. They became \"Carter's Little Pills\" in 1951. The phrase stuck but sometimes you hear the phrase without liver in it."},
    {true,"All hat and no cattle", "to be overly boastful about yourself without much to back it up"},
    {false,"Don't kick a cow turd on a hot day.", "Don't go asking for trouble. President Harry S. Truman is responsible for this hilariously colorful warning."},
    {true,"Don't know whether to scratch their watch or wind their butt", "Incredibly confused. The phrase is a little confusing itself, which only makes the point further."},
    {false,"That's about as useful as tits on a bull", "Only female dairy cows produce milk. Male cows are called bulls. And even if you could \"milk anything with nipples,\" bulls tend to be rather ornery. So, good luck with that."},
    {true,"Buggy", "shopping cart"},
    {true,"Used to could", "I used to be able to do that, now I can't."},
    {true,"Gussied up", "Dressed up or \"snazzy\" looking aka you're not wearing jeans and a t-shirt."},
    {true,"Snug as a bug in a rug", "Extremely comfortable"},
    {true,"Tan your hide", "Your'e up for a good whoopin' aka spanking."},
    {true,"Umpteen", "A lot or countless times."},
    {true,"Having a conniption", "Throwing a dramatic, overreactive fit. It's often over something small, but the reaction is anything but."},
    {true,"Heavens to Betsy", "An exclamation of surprise or astonishment, often used when something unexpected happens."},
    {true,"She's as pretty as a peach", "This is a high compliment on appearance, meaning beautiful."},
    {true,"If mama ain't happy, ain't nobody happy", "This reflects the idea that the household's mood depends on the mother's happiness."},
    {true,"Don't get your drawers in a wad", "A gentle reminder not to get too worked up over something minor. It's our way of saying, \"Calm down; it's not worth the fuss.\""},
    {true,"Well, slap my knee and call me silly", "An expression of surprise or astonishment, typically in response to unexpected news."},
    {true,"Gully washer", "An intense, heavy rainstorm that causes water to rush through ditches and gullies, often leading to temporary flooding"},
    {true,"That'll put hair on your chest", "A phrase used to describe something particularly strong or intense, often about food or drink that has a bold, powerful effect."},
    {true,"Kiss my grits and call it gravy", "A sassy way of dismissing someone's opinion or response to something you've done or said, signaling that you don't care what they think or say."},
    {true,"Butter my butt and call me a biscuit", "An expression of surprise or disbelief"},
    {true,"Hog wild", "Thrilled or enthusiastic, often acting with unchecked excitement or energy"},
    {true,"Give it a whirl", "Encourages someone to try something, even if they're unsure how it will turn out."},
    {true,"Hand to mouth", "Living with just enough to get by, often scraping together what's needed daily, with little to no extra for savings or luxuries."},
    {true,"Don't let the door hit ya where the good Lord split ya", "Please get out now as I don't care if the door hits you on the way out."},
    {true,"Like two peas in a pod", "These two people are inseparable and depend on each other for support and companionship."},
    {true,"Like water off a duck's back", "Hearing this phrase is a suggestion that you should let go of whatever ails you so it doesn't keep you soaked in anger or frustration for too long."},
    {true,"Christmas Eve gift!", "This is usually said on the morning of Dec. 24, with the goal of being the first person to say it. In some families, saying it can even result in receiving an extra gift, and may be a hug."},
    {true,"He's got ants in his pants", "Restless or unable to sit still"},
    {true,"Sweet tea makes everything better", "Or it is a serious problem"},
    {true,"He's as cool as a cucumber", "Very calm and composed"},
    {true,"Let's blow this popsicle stand", "Let's leave this place quickly"},
    {true,"Gag a maggot", "A phrase used to describe something that is extremely unpleasant or disgusting"},
    {true,"Go whole hog", "To do something completely or wholeheartedly"},
    {true,"Hold your own", "To maintain one's position or status"},
    {true,"In a New York minute", "Very quickly or suddenly"},
    {true,"Like a chicken on a junebug", "Very eager or enthusiastic about something"},
    {true,"They fell out of the ugly tree and hit every branch on the way down.", "Unattractive or very ill behaved"},
    {true,"It's like putting lipstick on a pig", "Superficial or cosmetic changes won't make something better, or different than what it is."},
    {true,"What in the Sam Hill?", "An expression of surprise or disbelief"},
    {true,"I'll tell you how the cow ate the cabbage", "I'm about (fixin') to tell you like it is"},
    {true,"If you can't run with the big dogs, stay on the porch", "If you can't keep up with the best, don't try to compete"},
    {true,"She's got more layers than an onion", "Someone who is complex and has many facets to their personality"},
    {true,"As the crow flies", "The shortest route between two points"},
    {true,"He's as happy as a clam at high tide", "Very happy and content"},
    {true,"Don't throw the baby out with the bathwater", "Don't discard something valuable while getting rid of something unwanted"},
    {true,"She's as sharp as a tack", "Very intelligent and quick-witted"},
    {true,"He's as busy as a one-armed paperhanger", "Extremely busy, often with limited resources"},
    {true,"Like trying to nail jelly to a tree", "An impossible or very difficult task"},
    {true,"She's got a heart of gold", "Very kind and generous"},
    {true,"About as helpful as a bump on a log","Not very helpful at all"},
    {true,"Don't count your chickens before they hatch", "Don't assume something will happen before it actually does"},
    {true,"They don't have a lick of sense", "No common sense at all is present"},
    {true,"As old as Methuselah", "Very old"},
    {true,"Uppity", "Snobby or snooty"},
    {true,"Skedaddle", "Let's get out of here"},
    {true,"I've got a hitch in my giddy-up (or get-along)","Some physical ailment is keeping you from moving like you need to"},
    {true,"Bright eyed and bushy tailed", "Eager and alert"},
    {true,"Fly off the handle", "Becomes angry quickly. Originated from the head flying off of a hammer."},
    {true,"Whistle britches", "Person who draws a lot of attention or is strong willed similar to a smarty pants. Sometimes heard with 'ole' added in front"},
    {true,"Fit to be tied", "So mad you should be restrained"},
    {true,"If it was a snake it woulda bit me!", "When what you're looking for is right in front of you"},
    {true,"Dadgummit, Dagnabit", "Polite curse words"},
    {true,"Get it while the gettin's good", "Do something while things are going well"},
    {true,"There's more than one way to skin a cat", "There's more than one way to do things"},
    {true,"Fish or cut bait", "Stop talking about it and take action"},
    {true,"Tump", "Tip or turn over accidentally"},
    {true,"I ain't got diddly squat", "To have nothing"},
    {true,"You can't get blood from a turnip", "You can't get anything from someone who has nothing to give"},
    {true,"I didn't just fall off the turnip truck", "I'm not naive or easily fooled"},
    {true,"Make hay while the sun shines", "Take advantage of opportunities when available"},
    {true,"Stove up", "Sore or stiff"},
    {true,"Ruckus", "A commotion"},
    {true,"There's not a pot too crooked that a lid won't fit","Southern positivity is expressed well with this one. It means there's someone out there for everyone."},
    {true,"We're so poor, we can't afford to pay attention","Southern way of expressing being very poor. Often combined with 'when I was growing up'"},
    {true,"Yes ma'am or yessir","While these are only good manners, Southerners say this often."},
    {true,"Sho nuff", "sure enough"},
    {true,"Close the door! You're letting all the good air out","Air conditioning is so valued in the South, and if you leave the door open too long, you will hear about it!"},
    {true,"Well that's the pot calling the kettle black","One person accuses another of a fault that the first person is also guilty of."},
    {true,"Eat up with the dumb","The dumb is strong in that one"},
    {true,"Like putting socks on a rooster","The task at hand is almost impossible"},
    {true,"Well goodness gracious","Exclamation used to express surprise, shock, or mild dismay"},
    {true,"Crawdads","Southerners call crawfish this"},
    {true,"Ragamuffin","If you look like a ragamuffin, you don't look good enough to leave the house."},
    {true,"The greatest thing since pockets in blue jeans", "This is a twist on the more common greatest thing since sliced bread, used to describe something particularly useful, clever, or innovative."},
    {true,"Slower than a Sunday afternoon", "Moving at a leisurely and peaceful pace"},
    {true,"He can't carry a tune in a bucket", "Someone who is a terrible singer"},
    {true,"She's catty-cornered to common sense", "Lacks logic or is acting irrationally"},
    {true,"Happy as a dead pig in the sunshine", "Content or satisfied, often used sarcastically"},
    {true,"Lit up like a Christmas tree", "Extremely excited or overly decorated"},
    {true,"Full of beans", "Energetic or lively"},
    {true,"Old as dirt", "Very old"},
    {false,"Ain't got a pot to piss in", "Very poor"},
    {true,"Wound up tighter than a two-dollar watch", "Extremely tense or stressed"},
    {true,"Sweet as pie", "Very kind or pleasant"},
    {true,"That just don't cut the mustard", "That's not good enough or doesn't meet standards"},
    {true,"Livin' high on the hog", "Living in luxury or comfort"},
    {true,"It's too wet to plow", "An excuse for being unable to work, often used as a general delay"},
    {true,"Like a bump on a log", "Sitting idle or inactive"},
    {true,"She's got more twists than a mountain road", "Describes someone unpredictable or complicated"},
    {true,"She thinks she's the only hen in the coop", "Believes they are the center of attention or special"},
    {true,"Tough as nails", "Resilient and strong"},
    {true,"Smooth as silk", "Very suave or polished in demeanor"},
    {true,"Full as a tick", "Completely full after eating"},
    {true,"Talking a blue streak", "Speaking very quickly and non-stop"},
    {true,"Don't let the bedbugs bite", "A common bedtime well-wish"},
    {true,"Good gravy!", "An exclamation of surprise"},
    {true,"He couldn't find his way out of a paper bag", "Completely lost or incompetent"},
    {true,"Dumb as a box of rocks", "Extremely unintelligent"},
    {true,"You can put your boots in the oven, but that don't make 'em biscuits", "Just because something seems like something doesn't mean it is that thing."},
    {true,"Don't get your feathers ruffled", "Don't get upset or agitated."},
    {true,"Well, that just dills my pickle!", "Expression of annoyance or frustration"},
    {true,"Grinning like a mule eating briars", "Smiling widely, often smugly"},
    {true,"She's wound tighter than an eight-day clock", "Very tense or high-strung"},
    {true,"Sweeter than a Georgia peach", "Extremely sweet or pleasant"},
    {true,"Hotter than a stolen tamale", "Very hot or under pressure"},
    {false,"Cold as a witch's tit in a brass bra", "Extremely cold"},
    {true,"That old boy's strong as an ox", "Very physically strong"},
    {true,"Like a moth to a flame", "Drawn irresistibly to something"},
    {true,"You look like you've been dragged through a knothole backwards", "Disheveled or exhausted appearance"},
    {true,"Stick out like a sore thumb", "Very noticeable or conspicuous"},
    {true,"More fun than a barrel of monkeys", "Extremely fun or entertaining"},
    {true,"No spring chicken", "Not young anymore"},
    {true,"Looks like something the cat dragged in", "Looks messy or unkempt"},
    {true,"Easy as pie", "Very easy to do"},
    {true,"Riding shotgun", "Sitting in the front passenger seat"},
    {true,"Doesn't have both oars in the water", "Mentally lacking or not thinking straight"},
    {true,"Naked as a jaybird", "Completely naked"},
    {true,"Don't bite off more than you can chew", "Don't take on more than you can handle"},
    {true,"Long in the tooth", "Old or aging"},
    {true,"Like shooting fish in a barrel", "Extremely easy"},
    {true,"If wishes were horses, beggars would ride", "Wishing for something doesn't make it happen"},
    {true,"More nervous than a turkey in November", "Extremely anxious"},
    {true,"Quick as greased lightning", "Very fast"},
    {true,"Like a fish out of water", "Feeling out of place or uncomfortable"},
    {true,"Can't see the forest for the trees", "Too focused on details to see the big picture"},
    {true,"Like putting the cart before the horse", "Doing things out of proper order"},
    {true,"Spitting image", "Looking exactly like someone else"},
    {true,"Right as rain", "Everything is fine or correct"},
    {true,"Hootin' and hollerin'", "Making a lot of noise, usually in celebration"},
    {true,"Balled the jack", "To move very fast or go all out"},
    {true,"Flew the coop", "Left or escaped"},
    {true,"Rode off into the sunset", "Left for good or moved on"},
    {true,"Don't take any wooden nickels", "Don't be fooled or cheated"},
    {true,"He's a few sandwiches short of a picnic", "Lacking intelligence"},
    {true,"All show and no go", "Looks good but lacks substance"},
    {true,"Cuter than a button", "Extremely cute"},
    {true,"Howdy", "Hello"},
    {true,"Y'all come back now, ya hear?", "A friendly invitation to return"},
    {true,"Cut the lights", "Turn off the lights"},
    {true,"Carry you somewhere", "Drive you somewhere"},
    {true,"Mash the button", "Press the button"},
    {true,"Pocketbook", "Purse"},
    {true,"Supper", "Dinner"},
    {true,"Do what now?", "Excuse me? or What did you say?"},
    {true,"How's your mom 'n 'em?", "How is your family?"},
    {true,"Lord have mercy!", "Expression of surprise or exasperation"},
    {true,"Bless it!", "Expression of sympathy or frustration"},
    {true,"Good night!", "Expression of surprise (not a goodbye)"},
    {true,"Land sakes!", "Expression of surprise or astonishment"},
    {true,"Oh my stars!", "Expression of surprise"},
    {true,"Well, I'll swan!", "Expression of shock or disbelief"},
    {true,"For crying out loud!", "Expression of frustration"},
    {true,"Lordy, Lordy!", "Expression of surprise or emphasis"},
    {false,"It's hotter than the hinges of hell.", "It's extremely hot"},
    {true,"Whatever floats your boat", "Whatever makes you happy"},
    {true,"Tickled pink", "Very pleased or delighted"},
    {true,"Sunday-go-to-meeting clothes", "Your best clothes"},
    {true,"Big ol'", "Big (used as an intensifier)"},
    {true,"Little bitty", "Very small"},
    {true,"Directly", "Soon or in a little while"},
    {true,"Don't get your tail feathers in a bunch", "Don't get upset"},
    {true,"At the end of my rope", "Frustrated or at my limit"},
    {true,"Two shakes of a lamb's tail", "Very quickly"},
    {true,"That's the way the cookie crumbles", "That's just how things happen"},
    {true,"Dead as a doornail", "Completely dead"},
    {false,"Grinnin' like a jackass eatin' briars", "Smiling widely, often in a silly or smug way"},
    {true,"In a coon's age", "In a very long time"},
    {true,"Gooder than grits", "Very good or excellent"},
    {false,"Don't make me open up a can of whoop-ass", "Don't provoke me to fight or punish you."},
    {true,"Fine and dandy", "Everything is great."},
    {true,"The apple doesn't fall far from the tree", "Children resemble their parents."},
    {true,"Don't put all your eggs in one basket", "Don't risk everything on one thing."},
    {true,"That'll preach!", "That's a great point or truth."},
    {true,"You don't say!", "Expression of surprise or interest"},
    {true,"He's mule-stubborn and twice as ornery","Not only stubborn but also very difficult to deal with"},
    {true,"Land o' Goshen!", "Expression of surprise. Goshen was the region in Egypt inhabited by the Israelites until the Exodus in the Bible."},
    {true,"My stars!", "Expression of surprise"},
    {true,"Fiddlesticks!", "Mild exclamation of annoyance"},
    {true,"Well, shut my mouth!", "Expression of surprise or disbelief"},
    {true,"Heavens above!", "Expression of surprise or exasperation"},
    {true,"Even a blind hog finds an acorn now and then","Even someone inept or unlucky will sometimes succeed."},
    {true,"Got your ears lowered","Got a haircut"},
    {true,"Haulin' tail","Moving very fast or rushing"},
    {true,"Ain't right","Something's off about that person."},
    {true,"Holler at me","Used in farewell saying like \"stay in touch\" or contact me when needed"},
    {true,"Maters","Tomatoes. Also, potatoes may be called taters, and sometimes a banana is called a nanner."},
    // new sayings on 2/2/2026
    {true,"If you want the rainbow, you gotta put up with the rain","You have to endure difficulties to enjoy the good times."},
    {true,"Ill as a hornet", "Very angry or upset"},
    {true,"I could chew up nails and spit out a barbed wire fence","Very angry or upset"},
    {true,"Bless your pea-pickin' little heart","Variation of bless your heart and may be affectionate or sarcastic depending on context"},
    {true,"I can't win for losing","Can't seem to succeed no matter what I do"},
    {true,"I'm as busy as a farmer with one hoe and two rattlesnakes","Having too much to do with inadequate resources"},
    {true,"He could talk the dogs off a meat truck","Very persuasive and charming"},
    {true,"Mess of catfish","Fried catfish is a staple of Southern food. A mess is enough to feed your family."},
    // new sayings on 2/3/2026
    {false,"Wait just a cotton pickin' minute","\"Cotton pickin'\" is a mild expletive to add emphasis without using \"damn\". This is a common way it is used."},
    {true,"Fer piece","A significant distance - You might hear, \"Billy Bob's house is a fer piece. Git in the truck and I'll carry you there.\""},
    {true,"More than you can shake a stick at","An expression meaning a large amount or number of something."},
    {true,"What fer?","Funny response to this is \"Cat fur, to make kitten britches.\""},
    // new sayings on 2/7/2026
    {true,"He may not be a chicken, but he has his henhouse ways","Timid and cautious"},
    {true,"He’s riding a gravy train with biscuit wheels","Lucky and comfortable"},
    {true,"He don't care what you call him as long as you call him to supper","He loves to eat"},
    {true,"Good ole boy", "A term used to describe a man who is considered a traditional, down-to-earth Southerner. The term can be used affectionately as someone who embodies the Southern values and lifestyle, such as hospitality, loyalty, and a strong sense of community. But, it can be used in a more critical way to describe someone who is perceived as old-fashioned or resistant to change."},
    {true,"Happy as a tick on a hound", "Extremely happy and content, often used to describe someone who is enjoying a situation or environment that suits them perfectly."},
    {false,"She's got more curves than a country road", "Attractive and curvy figure as a compliment"},
    {true,"Scared as a cat at a dog pound", "Nervous, frightened, or anxious"},
    {true,"Makes a pressure cooker look calm","Nervous, anxious, or under a lot of stress"},
    {true,"She could talk a coon right out of a tree", "Talkative"},
    {true,"Well, I'll be a monkey's uncle!", "Expression of great surprise"},
    {true,"Put a little paint on the barn", "Needs makeup applied"},
    {true,"Busier than a cow's tail in fly season", "Extremely busy or active"},
    {true,"Go around by Laura's house", "Take a longer or indirect route to get somewhere"},
    {true,"Now we're cookin' with grease", "Things are going well or progressing smoothly"},
    {true,"90 to nothing","Moving very fast or at full speed to get things done"},
    {true,"Take a gander", "Look at something"},
    {true,"Jump the broomstick", "Get married"},
    // added 2/9/2026
    {true,"As popular as a pole cat in a perfume factory", "someone is extremely unwelcome or highly disliked"},
    {true,"Were you raised in a barn?", "Close the door / You have no manners"},
    // added 2/10/2026
    {true,"Bet your boots","Absolutely certain"},
    {true,"You ain't just whistlin' Dixie","Someone is serious or not kidding around"},
    {true,"Rougher than a corn cob in an outhouse","Unpleasant or painful situation to deal with"},
    {true,"Scarce as deviled eggs at a Baptist picnic","Disappears quickly or is hard to come by"}
};

void outputSaying(const Saying& saying, int sayingIndex, bool separateLines = false, bool colored = false, bool noMeaning = false, bool showNumber = false) {
    string sayingColor = "\033[35m";  // pink
    string meaningColor = "\033[33m"; // orange
    string resetColor = "\033[0m";    // no color
    string label = showNumber ? "[" + to_string(sayingIndex + 1) + "] " : "";
    if (!colored) {
        sayingColor = meaningColor = resetColor = "";
    }
    if (noMeaning) {
        cout << label << sayingColor << saying.text << resetColor << "\n";
        if (separateLines) cout << "\n";
    } else {
        if (separateLines) {
            cout << label << sayingColor << saying.text << resetColor << "\n"
                 << meaningColor << saying.meaning << resetColor << "\n\n";
        } else {
            cout << label << sayingColor << saying.text << resetColor << ": "
                 << meaningColor << saying.meaning << resetColor << "\n";
        }
    }
}

void displayHelp() {
    cout << "Southern Sayings - A collection of Southern sayings with their meanings\n\n";
    cout << "Usage: ./southernsayings [OPTIONS]\n\n";
    cout << "Options:\n";
    cout << "  (none)               Display a single random saying (default)\n";
    cout << "  -a, --all            Display all sayings in shuffled order\n";
    cout << "  -1, --oneline        Display saying and meaning on one line with colon separator\n";
    cout << "  -c, --color          Colored output: pink for saying, orange for meaning\n";
    cout << "  -nm, --nomeaning     Display only the saying without the meaning\n";
    cout << "  -sn, --shownumber    Display the unique saying number in brackets\n";
    cout << "  -p, --pick [number]  Display a specific saying by number\n";
    cout << "      --polite         Display only sayings suitable for polite company\n";
    cout << "  -j, --json           Output all sayings in JSON format\n";
    cout << "  --csv                Output all sayings in CSV format\n";
    cout << "  -h, --help           Display this help message\n";
}

// Helper to escape characters for JSON output
string escapeJSON(const string& s) {
    string res;
    for (char c : s) {
        if (c == '"') res += "\\\"";
        else if (c == '\\') res += "\\\\";
        else if (c == '\b') res += "\\b";
        else if (c == '\f') res += "\\f";
        else if (c == '\n') res += "\\n";
        else if (c == '\r') res += "\\r";
        else if (c == '\t') res += "\\t";
        else res += c;
    }
    return res;
}

// Helper to escape characters for CSV output
string escapeCSV(const string& s) {
    string res = "\"";
    for (char c : s) {
        if (c == '"') res += "\"\"";
        else res += c;
    }
    res += "\"";
    return res;
}

int main(int argc, char* argv[]) {
    bool together = false, showAll = false, colored = false, noMeaning = false, showNumber = false, pickSpecific = false;
    bool politeOnly = false;
    bool impoliteOnly = false; // unadvertised option
    bool jsonOutput = false, csvOutput = false;
    int pickedNumber = -1;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-1" || arg == "--oneline") together = true;
        else if (arg == "-a" || arg == "--all") showAll = true;
        else if (arg == "-c" || arg == "--color") colored = true;
        else if (arg == "-nm" || arg == "--nomeaning") noMeaning = true;
        else if (arg == "-sn" || arg == "--shownumber") showNumber = true;
        else if (arg == "--impolite") impoliteOnly = true;
        else if (arg == "-j" || arg == "--json") jsonOutput = true;
        else if (arg == "--csv") csvOutput = true;
        else if (arg == "--polite") politeOnly = true;
        else if (arg == "-p" || arg == "--pick") {
            if (i + 1 < argc) {
                try {
                    pickedNumber = stoi(argv[++i]);
                    pickSpecific = true;
                } catch (...) {
                    cerr << "Error: --pick requires a valid number.\n";
                    return 1;
                }
            } else {
                cerr << "Error: --pick requires a number.\n";
                return 1;
            }
        } else if (arg == "-h" || arg == "--help") {
            displayHelp();
            return 0;
        }
    }
    if (impoliteOnly && politeOnly) {
        cerr << "It is impossible to be polite and impolite at the same time.\n";
        return 1;
    }
    // Create filtered list of indices based on politeOnly flag
    vector<int> availableIndices;
    for (size_t i = 0; i < southernSayings.size(); ++i) {
        if (impoliteOnly) {
            if (!southernSayings[i].okForPoliteCompany) {
                availableIndices.push_back(i);
            }
            continue;
        }
        else if (!politeOnly || southernSayings[i].okForPoliteCompany) {
            availableIndices.push_back(i);
        }
    }

    // Handle JSON output
    if (jsonOutput) {
        cout << "[\n";
        for (size_t i = 0; i < availableIndices.size(); ++i) {
            int idx = availableIndices[i];
            cout << "  {\n";
            cout << "    \"polite\": " << (southernSayings[idx].okForPoliteCompany ? "true" : "false" ) << ",\n";
            cout << "    \"text\": \"" << escapeJSON(southernSayings[idx].text) << "\",\n";
            cout << "    \"meaning\": \"" << escapeJSON(southernSayings[idx].meaning) << "\"\n";
            cout << "  }" << (i < availableIndices.size() - 1 ? "," : "") << "\n";
        }
        cout << "]\n";
        return 0;
    }

    // Handle CSV output
    if (csvOutput) {
        cout << "Polite,Text,Meaning\n";
        for (int idx : availableIndices) {
            cout << (southernSayings[idx].okForPoliteCompany ? "Yes" : "No") << "," << escapeCSV(southernSayings[idx].text) << "," << escapeCSV(southernSayings[idx].meaning) << "\n";
        }
        return 0;
    }

    bool separateLines = !together;
    // We work with indices to preserve the original association regardless of output order
    vector<int> originalIndices = availableIndices;

    if (showAll) {
        cout << "Southern Sayings - A collection of Southern sayings with their meanings\n\n";
        random_device rd;
        mt19937 gen(rd());
        shuffle(originalIndices.begin(), originalIndices.end(), gen);

        for (int idx : originalIndices) {
            outputSaying(southernSayings[idx], idx, separateLines, colored, noMeaning, showNumber);
        }
        cout << "\nTotal sayings: " << availableIndices.size() << "\n";
    } else if (pickSpecific) {
        if (pickedNumber >= 1 && pickedNumber <= static_cast<int>(southernSayings.size())) {
            int idx = pickedNumber - 1;
            // Check if this saying is available (not filtered out by politeOnly)
            if (find(availableIndices.begin(), availableIndices.end(), idx) != availableIndices.end()) {
                outputSaying(southernSayings[idx], idx, separateLines, colored, noMeaning, showNumber);
            } else {
                cerr << "Error: Saying #" << pickedNumber << " is not available with --polite filter\n";
                return 1;
            }
        } else {
            cerr << "Error: Picked number " << pickedNumber << " out of range (1-" << southernSayings.size() << ")\n";
            return 1;
        }
    } else {
        if (availableIndices.empty()) {
            cerr << "Error: No sayings available with current filters\n";
            return 1;
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, availableIndices.size() - 1);
        int randomIdx = availableIndices[dis(gen)];
        outputSaying(southernSayings[randomIdx], randomIdx, separateLines, colored, noMeaning, showNumber);
    }
    return 0;
}
