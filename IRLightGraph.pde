import processing.pdf.*;

import org.gicentre.utils.stat.*;    // For chart classes.
 
// Displays a simple line chart representing a time series.
XYChart lineChart;
//XYChart refers to the class, lineChart is an object in that class
// Loads data into the chart and customises its appearance.

String timestamp;
String titletime;
void setup()
{
  timestamp = year()+"-"+nf(month(),2)+"-"+nf(day(),2);
  titletime = year()+"."+nf(month(),2)+"."+nf(day(),2);
  size(1000,500); // sets the size of the window of the graph
  textFont(createFont("Arial",20),20);
 
  // Both x and y data set here.  
  lineChart = new XYChart(this);
  String[] data = loadStrings("/Users/DRYalacki/Documents/Engineering/LightData/"+timestamp+"-Compilation.txt");
  float[] IR  = new float[data.length-1];
  float[] time = new float[data.length-1];
  
  for (int i=0; i<data.length-1; i++)
  {
    String[] tokens = data[i+1].split("\t");
    IR[i]  = Float.parseFloat(tokens[0]);   // parses the data in the column into a floating point number
    time[i] = i;
} 
  lineChart.setData(time, IR);
   
  // Axis formatting and labels.
  lineChart.showXAxis(true); 
  lineChart.showYAxis(true); 
  float miny = IR[0];
  lineChart.setMinY(miny);
     
  lineChart.setYFormat("######");  // You can change the variable on the y axis data
  lineChart.setXFormat("0000");      // controls how many places are displayed on the x axis data
  lineChart.setXAxisLabel("\n Time "+  
                            "(Minutes)");
  lineChart.setYAxisLabel("IR Light Intensity (Relative Units) \n");
 
   
  // Symbol colours
  lineChart.setPointColour(color(180,50,50,200)); // the number at the end is intensity
  lineChart.setPointSize(6); 
  lineChart.setLineWidth(2);
}
 
// Draws the chart and a title.
void draw()
{
  String[] data = loadStrings("/Users/DRYalacki/Documents/Engineering/LightData/"+timestamp+"-Compilation.txt");
  float[] time = new float[data.length-1];
  for (int i=0; i<data.length-1; i++)
  {
    time[i] = i;
  }
  float finaltime = time[data.length-2];
  background(255);
  textSize(18);
  lineChart.draw(40,60,(width-100),(height-100));
      // Draw a title over the top of the chart.
  fill(120);
  textSize(36);
  text("IR Light Fluctuation for "+titletime, 150,30);
  textSize(22);
  text("Data recorded over "+finaltime+" minutes", 
        150,60);
  println("Finished.");
  save("IR_Light_Graph-"+titletime+".png");
  exit();
}