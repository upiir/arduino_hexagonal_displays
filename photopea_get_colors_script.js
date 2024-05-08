// Photopea script for getting pixel colors to be used for hexagonal displays
// please see the video for details
// YouTube video: https://youtu.be/1NI-I1Lpdqo
// WOKWI sketch: https://wokwi.com/projects/397321165094894593
// youtube channel: https://www.youtube.com/upir_upir

app.preferences.rulerUnits = Units.PIXELS; // set Photoshop/Photopea units to pixels

var array_sample_xy_positions = [ // positions of individual NeoPixels
[ 4, 1], 
[ 6, 1],
[ 8, 1],
[10, 1],

[3, 3],
[5, 3],
[7, 3],
[9, 3],
[11, 3],

[2, 5],
[4, 5],
[6, 5],
[8, 5],
[10, 5],
[12, 5],

[1, 7],
[3, 7],
[5, 7],
[7, 7],
[9, 7],
[11, 7],
[13, 7],

[2, 9],
[4, 9],
[6, 9],
[8, 9],
[10, 9],
[12, 9],

[3, 11],
[5, 11],
[7, 11],
[9, 11],
[11, 11],

[ 4, 13], 
[ 6, 13],
[ 8, 13],
[10, 13]
];


var string_colors = ""; // string to hold all RGB values
var pointSample = app.activeDocument.colorSamplers.add([0,0]); // add a new point sampler

for (let i = 0; i < array_sample_xy_positions.length; i++) { // go over every single NeoPixel (i.e. 2x2px area)

  pointSample.move([array_sample_xy_positions[i][0], array_sample_xy_positions[i][1]]); // move color sampler to a new position

  // get RGB values of the sampler and update the main string
  string_colors = string_colors + "/*NeoPixel: " + i + "*/ ";
  string_colors = string_colors + "" + pointSample.color.rgb.red + ", ";
  string_colors = string_colors + "" + pointSample.color.rgb.green + ", ";
  string_colors = string_colors + "" + pointSample.color.rgb.blue + ", \n";

}

pointSample.remove();  // remove the point sampler

// show the string with values so it can be copied into clipboard and used in the code
var value = prompt("COPY THIS", string_colors); 