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
//     command line version using modern C++20
//     version 1.0 - 1/26/2026
// Description: A collection of Southern sayings with their meanings.
//
// Command Line Options:
//   -1, --one        Display a single random saying
//   -s, --separate   Separate lines format: saying on one line, meaning on the next,
//                    then a blank line (useful for readable output)
//   -c, --color      Colored output: pink for saying, orange for meaning
//   -nm, --nomeaning Display only the saying without the meaning
//   -h, --help       Display this help message
//   (none)           Display all sayings in shuffled order

#include <array>
#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

struct Saying {
    string text;
    string meaning;
};

const vector<Saying> southernSayings = {
    {"Hotter than a billy goat in a pepper patch", "It's unbearably hot and almost comically so"},
    {"Colder than a well digger's behind in January", "It's freezing cold, often used during a sharp winter morning"},
    {"It's so hot the hens are laying hard-boiled eggs.", "A funny way to exaggerate the high temperature"},
    {"It's raining like a cow peeing on a flat rock.", "Describes a sudden heavy rain with a splashy and chaotic feel"},
    {"Hotter than blue blazes", "Describes etremely hot and hellish southern heat"},
    {"So humid, I could wring out the air", "Describes the sticky, muggy humidity"},
    {"The devil's beating his wife.", "The sun is shining while it is raining at the same time."},
    {"Sweatin' like a sinner in church", "Used when someone is uncomfortably hot or nervous"},
    {"Don't know him from Adam's house cat", "Describing a stranger"},
    {"Feels like the Lord left the oven door open", "Used when the weather is oppressively hot and dry"},
    {"About as useful as a screen door on a submarine", "A humorous way to say someone seems useless"},
    {"He's got more nerve than a bum tooth", "Describes someone who is bold or has no shame"},
    {"She could start an argument in an empty house.", "A drama stirrer or someone always picking a fight"},
    {"He's slicker than a greased pig at a county fair.", "Someone who's cunning or hard to catch figuratively"},
    {"Prettier than a speckled pup under a red wagon", "Means someone is absolutely adorable and attractive"},
    {"Dumber than a bag of hammers", "Used to call someone foolish or unintelligent"},
    {"Fixin' to", "This person is about to do something."},
    {"Lower than a snake's belly in a ditch", "Refers to someone with no moral backbone"},
    {"Got a face for radio", "A backhanded way of saying someone isn't very photogenic"},
    {"Crazier than a sprayed roach", "Someone acting wildly or irrationally - also you may hear 'crazier than a betsy bug'"},
    {"Lazy as a hound dog on a porch swing", "Extremely lazy and content to stay idle"},
    {"Wouldn't hit a lick at a snake", "Describes someone who won't even make a slight effort"},
    {"Too lazy to scratch an itch", "Someone who refuses to do even basic tasks"},
    {"Rather climb a tree to tell a lie than stand on the ground and tell the truth", "A twist on laziness with deception added in"},
    {"Moves slower than molasses in January", "Someone who takes his sweet time, and drags his feet!"},
    {"Can't be bothered unless there's gravy involved", "Only works if there's a personal payoff"},
    {"So lazy he'd rather sleep standing up than find a place to lie down", "Comically exaggerates someone's unwillingness to make effort"},
    {"If work was a fire, he'd freeze to death", "A jab at someone who avoids work at all costs"},
    {"Got a Ph.D. in doing nothing", "Humorous way to label someone professionally lazy"},
    {"Lazier than a toad on a lily pad", "Slow and stationary, just soaking up life"},
    {"He's a few fries short of a Happy Meal", "Not very bright or lacking common sense"},
    {"If brains were leather, he wouldn't have enough to saddle a June bug.", "Extremely unintelligent"},
    {"The porch light's on, but nobody's home.", "Someone looks alert but isn't really mentally present"},
    {"Sharp as a mashed potato sandwich", "A humorous insult for someone lacking intellect"},
    {"One biscuit shy of a breakfast", "A subtle, funny way to say someone's a bit off mentally"},
    {"Couldn't pour water out of a boot with instructions on the heel", "Someone who's totally clueless"},
    {"Not the brightest crayon in the box", "Lacks intelligence or awareness"},
    {"If ignorance was bliss, he'd be the happiest man alive.", "Extremely uninformed or naive"},
    {"Got the IQ of a pinecone", "Sarcastic way to say someone is intellectually lacking"},
    {"Dumber than dirt", "Simple, blunt, and classic southern jab"},
    {"Tighter than bark on a tree when it comes to money", "Very frugal or stingy"},
    {"Been rode hard and put up wet", "Someone who looks worn out or rough around the edges"},
    {"Family trees in some parts don't fork.", "A joke about inbreeding or lack of diversity in relationships"},
    {"Nuttier than a fruitcake", "Used to describe an eccentric or unpredictable person"},
    {"That boy's momma didn't raise no fool.", "A way to say someone's smart or knows better"},
    {"She's as high-maintenance as a show pony.", "A partner or relative who requires a lot of attention"},
    {"He's married, but the fence still has a few holes in it.", "Suggesting infidelity or lack of commitment"},
    {"Kin to everybody and nobody at the same time", "Refers to someone who claims lots of relations, often loose ones"},
    {"Got more baggage than Atlanta airport", "Someone who comes with a lot of emotional history and drama"},
    {"More whipped than a bowl of mashed potatoes", "Someone overly submissive in a relationship"},
    {"Nervous as a long-tailed cat in a room full of rocking chairs", "Extremely anxious or jumpy"},
    {"Happy as a pig in slop", "Completely content and satisfied"},
    {"Busy as a one-legged cat in a sandbox", "Overwhelmed or trying hard to manage a lot."},
    {"Crooked as a dog's hind leg", "Refers to someone dishonest or shady"},
    {"Uglier than a mud fence after a rainstorm", "A brutal way to call someone unattractive"},
    {"Like herding cats", "Trying to control a chaotic or unmanageable situation"},
    {"Like a possum playing dead", "Avoids problems or pretends not to notice them"},
    {"Meaner than a skillet full of rattlesnakes", "Describes someone especially vicious or angry"},
    {"More tricks than a squirrel in a corn crib", "Someone who's clever or sneaky"},
    {"Runs around like a chicken with its head cut off", "Acting frantic or disorganized in an inefficient way"},
    {"Between a rock and a hard place", "Stuck in a situation where there are no good choices"},
    {"If it were raining soup, I'd get hit with a fork.", "Nothing ever goes right for this person"},
    {"Tougher than a two-dollar steak", "Describes something or someone extremely resilient or hard to handle"},
    {"I'm hanging on by a thread.", "Barely managing to hold it together - mentally, emotionally, or financially"},
    {"This ain't my first rodeo.", "A way to say you've been through hard times before or done this enough to be familiar with it"},
    {"That dog won't hunt.", "The plan or idea won't work"},
    {"Up a creek without a paddle", "In a bad situation with no clear way out"},
    {"Tighter than Dick's hatband", "Extremely cheap or stingy or strange"},
    {"That man squeezes a penny so hard, Abe Lincoln cries.", "A vivid exaggeration of frugality"},
    {"She's got champagne taste on a beer budget.", "Loves expensive things but can't afford them"},
    {"He works harder than a one-eyed dog in a smokehouse.", "Someone who works extremely hard"},
    {"Got more money than sense", "Rich, but lacking good judgment"},
    {"Wouldn't give you the time of day unless it made him a nickel", "Very self-serving or greedy"},
    {"Busier than a termite in a sawmill", "Incredibly busy or industrious"},
    {"Spends money like it's going out of style", "Carelessly extravagant with money"},
    {"Tighter than a new pair of boots", "Can describe both stinginess and discomfort in spending"},
    {"Bless your heart", "Could be sympathy or a subtle way of calling you an idiot"},
    {"She's got a good personality.", "Code for someone who isn't physically attractive"},
    {"He's not the sharpest knife in the drawer.", "A gentle way of saying someone isn't intelligent"},
    {"Well, that's one way to do it.", "Passive-aggressive disapproval masked as openness"},
    {"He means well.", "Someone who tries but often fails or messes things up"},
    {"She's a handful!", "A polite way of saying someone's difficult and/or dramatic, and might include the word real in front of handful"},
    {"He could eat corn through a picket fence.", "Describes someone with gapped teeth"},
    {"Beats all I've ever seen.", "That tops everything. Variations: beats all I ever did see, beats all, that beats all"},
    {"You'd have to water that idea for it to grow.", "A humorous way of calling it a dumb idea"},
    {"She's a real peach, with a pit.", "She seems sweet but she has a mean streak"},
    {"He's slicker than owl snot.", "Describes someone charming and maybe too much so"},
    {"She's sweeter than a June bug on a honeysuckle vine", "An adorable person with great behavior"},
    {"He's been bit by the love bug", "Clearly smitten or falling in love"},
    {"She put a spell on him stronger than grandma's moonshine", "Deeply infatuated and under someone's charm"},
    {"He's more whipped than mashed taters at a church supper", "Comically devoted or overly obedient in a relationship"},
    {"She could charm the socks off a rooster", "Very flirtatious"},
    {"Well, I'll be?", "Expressing pure and wide-eyed astonishment"},
    {"I'll be derned", "Expression of surprise"},
    {"Possum in a rosebush!", "Expression of surprise"},
    {"Would argue with a fence post", "This describes someone very argumentative, so much they would argue with an inanimate object."},
    {"Like a hair on a biscuit", "Describes someone who is annoying or out of place"},
    {"We're living in high cotton.", "Experiencing a time of well being"},
    {"What's got you all cattywampus?", "Askew, disordered, or crooked"},
    {"He was three sheets to the wind.", "He was intoxicated"},
    {"It's over yonder.", "A general direction, not a specific place, and it might not be within reach but generally within sight"},
    {"He's having a hissy fit.", "An adult having a full melt down and emotional outburst"},
    {"Quit bein' ugly.", "This has nothing to do with looks - stop being mean, rude, or acting uncouth"},
    {"That doesn't amount to a hill of beans.", "Something of little importance or value"},
    {"Lord willing and if the creeks don't rise.", "A phrase that means if everything goes according to plan and likely originated from early 19th century travelers who had to cross creeks"},
    {"He's silly as all get out.", "Utmost silliness"},
    {"If I had my druthers", "If I had my choice"},
    {"I'm finer than frog hair and not half as slick.", "A funny response to 'How are you?'"},
    {"Don't try to plow through the stump.", "Farm wisdom about choosing the wiser path instead of the hardest one"},
    {"He was plumb tuckered out.", "Extremely tired or exhausted - Plumb may be a general inensifier word using in other sayings"},
    {"You can catch more flies with honey than with vinegar.", "A proverb about the power of persuasion sometimes used when someone is being 'ugly' in the southern sense"},
    {"She thinks she's so high falutin'.", "Very pretentious"},
    {"Coke", "Not just referring to Coca-Cola but any carbonated soda"},
    {"Too big for his britches", "Someone obviously full of themselves"},
    {"Blowin' up a storm", "You may hear a Southerner say this when the wind picks up and the skies get cloudy."},
    {"I'm so full, I'm about to pop", "What you might hear from a Southerner after a hearty meal - also full as a tick may be used"},
    {"Y'all", "a common Southern phrase as you and all squished together - but don't confuse it with \"all y'all\" which is a group larger than two people"},
    {"He thinks the sun comes up just to hear him crow.", "Conceited"},
    {"Til the cows come home", "Cows tend to take their time, so this means it could be all day or a long time at least"},
    {"Doohickey", "When a Southerner can't think of a particular name for something, it suddenly becomes a doohickey."},
    {"Cornbread ain't done in the middle", "Describes someone who is \"off\" in some way"},
    {"Fair is a place where pigs get judged", "This is used when you have to tell someone that life isn't always fair. 4H competitions at County and State Fairs are common throughout the South."},
    {"Tore up", "A person who is truly upset by something"},
    {"Don't have a dog in this fight", "This is heard from a Southerner who doesn't care one way or the other about the matter at hand."},
    {"A month of Sundays", "A very long time. It might be in reference to something like not visiting your mom for a while."},
    {"Piddlin'", "A piddlin' is a small amount that's not worth bothering with. Someone who is piddlin' in the yard is wasting time and not doing much."},
    {"Gimme some sugar", "What Grandma says when you pull in the driveway, pop out of the car, and come running. She's not looking for sweets; she wants a hug and a kiss."},
    {"Well, I declare!", "A Southerner using this phrase could be declaring any number of things: surprise, dissent, happiness. The only requirement is that you declare it loud and proud."},
    {"Hush your mouth", "A Southerner might use this to tell someone to stop complaining or to be quiet. It's also used to tell someone to stop being a baby."},
    {"I'll tell you what", "This is a point of emphasis and exclamation that often ends without any additional telling at all. It can also be the opening to striking a bargain, sharing a strongly held opinion, or offering a piece of advice you may or may not want to hear."},
    {"I reckon", "This can mean -- I suppose, I think, or I imagine. It is a quintessential Southern phrase, said by friends and family on porches and in rocking chairs all across the South."},
    {"It'll make ya wanna slap your mama", "Used to describe something that's so good that you might do something unthinkable or extreme as a result. It's often used to describe food that's insanely delicious."},
    {"A rooster one day and a feather duster the next", "This is a Southerner's creative way of saying that you shouldn't crow like a rooster about your wealth and belonging today, because it could all disappear tomorrow."},
    {"He ain't got the sense God gave a goose", "This is another nice way to say that someone is lacking in brain power."},
    {"Pretty is as pretty does", "Similar to the phrase 'quit being ugly,' this one alludes to what's on the inside, not the outside, that matters. The expression is a simple reminder, often given to children, to remind them to be kind to others and mind their manners."},
    {"Can't never could", "This is positive thinking, Southern style."},
    {"Preachin' to the choir", "something to quit doing when trying to convince someone who already agrees with you"},
    {"It'll all come out in the wash", "Like dirt and stains, worries and problems will wash away. Whatever is bothering you isn't serious, and it will eventually be resolved with no lasting effects and that means don't worry."},
    {"You can't make a silk purse out of a sow's ear", "No matter how hard you try, you just can't make something pretty out of something ugly."},
    {"It's raining cats and dogs!", "This means that it's a downpour and not that kittens and puppies are literally falling from the sky."},
    {"Aren't you precious?", "Likely full of sarcasm, unless directed toward an adorable child"},
    {"You're barking up the wrong tree.", "When you're very much in the wrong, you might hear this phrase. Another way this can be used is if someone is telling you to back off."},
    {"Hold your horses.", "This means to stop what you're doing, or to calm down."},
    {"Who licked the red off your candy?", "asked when there is a wondering why the person is so upset"},
    {"My eyeballs are floating!", "When you want to express just how badly you need the restroom, but you don't want to say it, use this phrase instead!"},
    {"She's madder than a wet hen.", "Someone is very angry and may need some time to cool down."},
    {"I been running all over hell's half acre.", "When your day has ended up with the Southerner going to many more places than he originally wanted or planned, you might hear this."},
    {"She's got a mind like a steel trap, but it's rusted shut.", "Intelligence doesn't matter if you're unwilling to use it."},
    {"She's busier than a cat covering poop on a marble floor.", "Don't mistake motion for progress."},
    {"Don't go to the devil for advice on how to fight temptation.", "Be mindful of where you seek guidance and wisdom."},
    {"She's happier than a pig in a sunflower patch.", "Appreciate the simple joys in life."},
    {"He's running like a scalded dog.", "Sometimes urgency is the best motivator."},
    {"That'll jar your preserves", "Be ready for unexpected surprises in life."},
    {"He's as lost as last year's Easter egg.", "Keep track of what matters or you might lose it."},
    {"She's sweeter than tea with a double dose of sugar.", "kindness never goes out of style."},
    {"Jumpy as a frog on a hot skillet", "Try to learn to stay calm under pressure."},
    {"She's like a hen trying to crow.", "Stay true to who you are, not who others want you to be."},
    {"If it ain't broke, don't fix it.", "Sometimes, simplicity is best."},
    {"Diggin' a hole deeper than a gopher on double time", "Know when to stop making things worse. (also faster than a and in springtime)"},
    {"He's got more excuses than a dog has fleas.", "Own your mistakes and don't try to justify them."},
    {"He's as stubborn as a mule in a mud pit.", "Flexibility is key to success."},
    {"She's holdin' on tighter than a tick on a hound.", "Know when to let go of things that no longer server you."},
    {"He's walkin' on thin ice in cowboy boots.", "Be careful where you tread. However, sometimes, the best decisions are the ones that come with the most risk."},
    {"She's spreadin' gossip faster than butter on a hot biscuit.", "Guard your words as they can travel swiftly."},
    {"That idea's about as good as a screen door on a tornado shelter.", "Think things through before acting on it."},
    {"Don't let the tail wag the dog.", "Keep control of your priorities."},
    {"He's like a one-legged man in a butt-kicking contest.", "Don't take on more than you can handle."},
    {"You can't make chicken salad out of chicken scratch.", "Use quality resources for quality outcomes."},
    {"He's as unpredictable as a bull in a china shop.", "Be mindful of how your actions may impact others."},
    {"She's shining brighter than a new penny in sunlight.", "Confidence is an accessory to success."},
    {"She's got a heart bigger than the state of Texas.", "Generosity enriches lives and strengthens communities."},
    {"She's like a firecracker on the Fourth of July", "Enthusiasm and energy are contagious."},
    {"That's a tough row to hoe.", "Hard work pays off."},
    {"Tarnation", "some believe this could be a mixture of eternal and damnation. This is usually said like, \"What in tarnation?\" as being shocked by something to get you agitated about."},
    {"Hankering", "This means getting a strong desire for something like fried chicken."},
    {"Fair to middlin'", "This means doing all right, but not too good or bad - just in the middle."},
    {"Ugly as sin", "This is something rather unsightly or unpleasant."},
    {"Fit as a fiddle", "In good health and spirits"},
    {"Knee-high to a grasshopper", "This is a hyperbolic expression meaning very young, as in I haven't seen him since he was knee-high to a grasshopper."},
    {"Happy as a lark", "This is someone or something that is very happy."},
    {"Drunker than Cooter Brown", "This was a real person who lived along the Mason-Dixon line during the civil war. As the years went by, Cooter Brown's reputation grew, and his name became synonymous with someone who was always inebriated."},
    {"Clean as a whistle", "Someone who is innocent or something is entirely clean and dirt-free, judging from its apppearance"},
    {"Scarce as hen's teeth", "This is something very rare or difficult to find. Hens do not have teeth."},
    {"She's got more nerve than Carter's got liver pills", "Carters Products started as a pill-peddling company in the 19th century. Carters repped its \"Little Liver Pills\" so hard a Southern saying spawned from the advertisements. Alas, the Federal Trade Commission forced the drug-group to drop the \"liver\" portion of the ad, claiming it was deceptive. They became \"Carter's Little Pills\" in 1951. The phrase stuck but sometimes you hear the phrase without liver in it."},
    {"All hat and no cattle", "to be overly boastful about yourself without much to back it up"},
    {"Don't kick a cow turd on a hot day.", "Don't go asking for trouble. President Harry S. Truman is responsible for this hilariously colorful warning."},
    {"Don't know whether to scratch their watch or wind their butt", "Incredibly confused. The phrase is a little confusing itself, which only makes the point further."},
    {"That's about as useful as tits on a bull.", "Only female dairy cows produce milk. Male cows are called bulls. And even if you could \"milk anything with nipples,\" bulls tend to be rather ornery. So, good luck with that."},
    {"Buggy", "shopping cart"},
    {"Used to could", "I used to be able to do that, now I can't."},
    {"Gussied up", "Dressed up or \"snazzy\" looking aka you're not wearing jeans and a t-shirt."},
    {"Snug as a bug in a rug", "Extremely comfortable"},
    {"Tan your hide", "Your'e up for a good whoopin' aka spanking."},
    {"Umpteen", "A lot or countless times."},
    {"Having a conniption", "Throwing a dramatic, overreactive fit. It's often over something small, but the reaction is anything but."},
    {"Heavens to Betsy", "An exclamation of surprise or astonishment, often used when something unexpected happens."},
    {"She's as pretty as a peach", "This is a high compliment on appearance, meaning beautiful."},
    {"If mama ain't happy, ain't nobody happy", "This reflects the idea that the household's mood depends on the mother's happiness."},
    {"Don't get your drawers in a wad", "A gentle reminder not to get too worked up over something minor. It's our way of saying, \"Calm down; it's not worth the fuss.\""},
    {"Well, slap my knee and call me silly", "An expression of surprise or astonishment, typically in response to unexpected news."},
    {"Gully washer", "An intense, heavy rainstorm that causes water to rush through ditches and gullies, often leading to temporary flooding"},
    {"That'll put hair on your chest", "A phrase used to describe something particularly strong or intense, often about food or drink that has a bold, powerful effect."},
    {"Kiss my grits and call it gravy", "A sassy way of dismissing someone's opinion or response to something you've done or said, signaling that you don't care what they think or say."},
    {"Butter my butt and call me a biscuit", "An expression of surprise or disbelief, similar to saying, \"Well, I'll be!\""},
    {"Hog wild", "Thrilled or enthusiastic, often acting with unchecked excitement or energy"},
    {"Give it a whirl", "Encourages someone to try something, even if they're unsure how it will turn out."},
    {"Hand to mouth", "Living with just enough to get by, often scraping together what's needed daily, with little to no extra for savings or luxuries."},
    {"Don't let the door hit ya where the good Lord split ya", "Please get out now as I don't care if the door hits you on the way out."},
    {"Like two peas in a pod", "These two people are inseparable and depend on each other for support and companionship."},
    {"Like water off a duck's back", "Hearing this phrase is a suggestion that you should let go of whatever ails you so it doesn't keep you soaked in anger or frustration for too long."},
    {"Christmas Eve gift!", "This is usually said on the morning of Dec. 24, with the goal of being the first person to say it. In some families, saying it can even result in receiving an extra gift, and may be a hug."},
    {"He's got ants in his pants.", "Restless or unable to sit still"},
    {"Sweet tea makes everything better", "Or it is a serious problem"},
    {"He's as cool as a cucumber", "Very calm and composed"},
    {"Let's blow this popsicle stand", "Let's leave this place quickly"},
    {"Gag a maggot", "A phrase used to describe something that is extremely unpleasant or disgusting"},
    {"Go whole hog", "To do something completely or wholeheartedly"},
    {"Hold your own", "To maintain one's position or status"},
    {"In a New York minute", "Very quickly or suddenly"},
    {"Like a chicken on a junebug", "Very eager or enthusiastic about something"},
    {"They fell out of the ugly tree and hit every branch on the way down.", "Unattractive or very ill behaved"},
    {"It's like putting lipstick on a pig.", "Superficial or cosmetic changes won't make something better, or different than what it is."},
    {"What in the Sam Hill?", "An expression of surprise or disbelief"},
    {"I'll tell you how the cow ate the cabbage", "I'm about (fixin') to tell you like it is"},
    {"If you can't run with the big dogs, stay on the porch", "If you can't keep up with the best, don't try to compete."},
    {"She's got more layers than an onion", "Someone who is complex and has many facets to their personality"},
    {"As the crow flies", "The shortest route between two points"},
    {"He's as happy as a clam at high tide", "Very happy and content"},
    {"Don't throw the baby out with the bathwater.", "Don't discard something valuable while getting rid of something unwanted."},
    {"She's as sharp as a tack", "Very intelligent and quick-witted"},
    {"He's as busy as a one-armed paperhanger", "Extremely busy, often with limited resources"},
    {"Like trying to nail jelly to a tree", "An impossible or very difficult task"},
    {"She's got a heart of gold", "Very kind and generous"},
    {"About as helpful as a bump on a log","Not very helpful at all"},
    {"Don't count your chickens before they hatch", "Don't assume something will happen before it actually does"},
    {"They don't have a lick of sense", "No common sense at all is present"},
    {"As old as Methuselah", "Very old"},
    {"Uppity", "Snobby or snooty"},
    {"Skedaddle", "Let's get out of here."},
    {"I've got a hitch in my giddy-up (or get-along)","Some physical ailment is keeping you from moving like you need to"},
    {"Bright eyed and bushy tailed", "Eager and alert"},
    {"Fly off the handle", "Becomes angry quickly. Originated from the head flying off of a hammer."},
    {"Whistle britches", "Person who draws a lot of attention or is strong willed similar to a smarty pants. Sometimes heard with 'ole' added in front"},
    {"Fit to be tied", "So mad you should be restrained"},
    {"If it was a snake it woulda bit me!", "When what you're looking for is right in front of you"},
    {"Dadgummit, Dagnabit", "Polite curse words"},
    {"Get it while the gettin's good", "Do something while things are going well"},
    {"There's more than one way to skin a cat.", "There's more than one way to do things."},
    {"Fish or cut bait.", "Stop talking about it and take action."},
    {"Tump", "Tip or turn over accidentally"},
    {"I ain't got diddly squat.", "To have nothing"},
    {"You can't get blood from a turnip.", "You can't get anything from someone who has nothing to give."},
    {"I didn't just fall off the turnip truck.", "I'm not naive or easily fooled."},
    {"Make hay while the sun shines.", "Take advantage of opportunities when available."},
    {"Stove up", "Sore or stiff"},
    {"Ruckus", "A commotion"},
    {"There's not a pot too crooked that a lid won't fit.","Southern positivity is expressed well with this one. It means there's someone out there for everyone."},
    {"We're so poor, we can't afford to pay attention.","Southern way of expressing being very poor. Often combined with 'when I was growing up'"},
    {"Yes ma'am or yessir","While these are only good manners, Southerners say this often."},
    {"Sho nuff", "sure enough"},
    {"Close the door! You're letting all the good air out.","Air conditioning is so valued in the South, and if you leave the door open too long, you will hear about it!"},
    {"Well that's the pot calling the kettle black.","One person accuses another of a fault that the first person is also guilty of."},
    {"Eat up with the dumb","The dumb is strong in that one."},
    {"Like putting socks on a rooster","The task at hand is almost impossible."},
    {"Well goodness gracious","Exclamation used to express surprise, shock, or mild dismay"},
    {"Crawdads","Southerners call crawfish this."},
    {"Ragamuffin","If you look like a ragamuffin, you don't look good enough to leave the house."}
};

void outputSaying(const Saying& saying, bool separateLines = false, bool colored = false, bool noMeaning = false) {
    // ANSI color codes
    const string pinkColor = "\033[35m";      // Pink/Magenta
    const string orangeColor = "\033[33m";   // Orange/Yellow
    const string resetColor = "\033[0m";     // Reset to default
    
    if (noMeaning) {
        // Only display the saying
        if (colored) {
            std::cout << pinkColor << saying.text << resetColor << "\n";
        } else {
            std::cout << saying.text << "\n";
        }
        if (separateLines) {
            std::cout << "\n";
        }
    } else if (colored) {
        if (separateLines) {
            std::cout << pinkColor << saying.text << resetColor << "\n"
                      << orangeColor << saying.meaning << resetColor << "\n\n";
        } else {
            std::cout << pinkColor << saying.text << resetColor << ": "
                      << orangeColor << saying.meaning << resetColor << "\n";
        }
    } else {
        if (separateLines) {
            std::cout << saying.text << "\n" << saying.meaning << "\n\n";
        } else {
            std::cout << saying.text << ": " << saying.meaning << "\n";
        }
    }
}

void displayHelp() {
    std::cout << "Southern Sayings - A collection of Southern sayings with their meanings\n\n";
    std::cout << "Usage: ./southernsayings [OPTIONS]\n\n";
    std::cout << "Options:\n";
    std::cout << "  -1, --one        Display a single random saying\n";
    std::cout << "  -s, --separate   Separate lines format: saying on one line, meaning on the next,\n";
    std::cout << "                   then a blank line (useful for readable output)\n";
    std::cout << "  -c, --color      Colored output: pink for saying, orange for meaning\n";
    std::cout << "  -nm, --nomeaning Display only the saying without the meaning\n";
    std::cout << "  -h, --help       Display this help message\n";
    std::cout << "  (none)           Display all sayings in shuffled order\n\n";
    std::cout << "Examples:\n";
    std::cout << "  ./southernsayings                  - Display all sayings shuffled\n";
    std::cout << "  ./southernsayings -1               - Display one random saying\n";
    std::cout << "  ./southernsayings --color --separate - Display all sayings with colors and separate lines\n";
    std::cout << "  ./southernsayings --one --color    - Display one random saying in color\n";
    std::cout << "  ./southernsayings -nm              - Display all sayings without meanings\n";
}

int main(int argc, char* argv[]) {
    // Parse command line options
    bool separateLines = false;
    bool randomSingle = false;
    bool colored = false;
    bool noMeaning = false;
    
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-s" || string(argv[i]) == "--separate") {
            separateLines = true;
        } else if (string(argv[i]) == "-1" || string(argv[i]) == "--one") {
            randomSingle = true;
        } else if (string(argv[i]) == "-c" || string(argv[i]) == "--color") {
            colored = true;
        } else if (string(argv[i]) == "-nm" || string(argv[i]) == "--nomeaning") {
            noMeaning = true;
        } else if (string(argv[i]) == "-h" || string(argv[i]) == "--help") {
            displayHelp();
            return 0;
        }
    }
    
    if (randomSingle) {
        // Display a single random saying
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, southernSayings.size() - 1);
        
        const auto& saying = southernSayings[dis(gen)];
        outputSaying(saying, separateLines, colored, noMeaning);
    } else {
        // Display all sayings (shuffled)
        std::cout << "Southern Sayings - A collection of Southern sayings with their meanings\n";
        std::cout << "Brought to you by Code Life\n\n";
        
        auto sayingsCopy = southernSayings;
        random_device rd;
        mt19937 gen(rd());
        std::shuffle(sayingsCopy.begin(), sayingsCopy.end(), gen);
        
        for (const auto& saying : sayingsCopy) {
            // Print each saying and its meaning
            outputSaying(saying, separateLines, colored, noMeaning);
        }
        
        std::cout << "\nTotal sayings: " << southernSayings.size() << "\n";
    }
    return 0;
}
