# PcRGB
<a rel="license" href="http://creativecommons.org/licenses/by/2.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/2.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/2.0/">Creative Commons Attribution 2.0 Generic License</a>

Your gaming PC doesn't have RGB?! Just buy some! But what if your motherboard doesn't support it either? Well... Build your own controller!

## The project Briefly 
This tutorial shows you how you can create your own RGB controller for use anywhere in your house. Including your gaming PC with little if ANY cost.
We are using Arduino and some LED strips or fans.

**There is a Bluetooth controlled version coming to which you will be able to upgrade from any of the current versions.**

## Required matterials
![ListOfMaterials](https://github.com/nickiliopoulosedu/PcRGB/blob/main/Images/Reuired%20Materials.png)

The average total cost is around **24 dollars** including not required materials.

The list of all materials can be found in [Required Materials.xlsx][MaterialList]

## Circuit
**Animated**|**Schematic**  
------------|-------------
![GraphicalConnection](https://github.com/nickiliopoulosedu/PcRGB/blob/main/Images/Schematics_graphical.png)|![ScematicConnection](https://github.com/nickiliopoulosedu/PcRGB/blob/main/Images/Schematics_schem.png)

You can see a higher resolution version of the [**Schematic**][schem] and [**Animated Schematic**][schemAnim] or download the [**Fritzing (.fzz)**][Fritzing] file to edit them.

If you decide to not use some not necessary parts just exclude them and their wires. If you upload the corresponding code for your changes everything should work just fine.

## Code 
After building the circuit it is time to test it.

Locate the code that corresponds to the parts you have excluded (if any), connect to the Arduino via USB, select the port the Arduino is connected, change board to Arduino nano and the Processor (according to your board. I sugget figuring out which one you have with trial and error. Then, upload the sketch.

### Choose the correct program to load
* []
- []mething
- [ ]somehting else | tsiou

[MaterialList]: <https://github.com/nickiliopoulosedu/PcRGB/raw/main/Required%20Materials.xlsx>
[schem]: <https://github.com/nickiliopoulosedu/PcRGB/raw/main/Images/Schematics_schem.png>
[schemAnim]: <https://github.com/nickiliopoulosedu/PcRGB/raw/main/Images/Schematics_graphical.png>
[Fritzing]: <https://github.com/nickiliopoulosedu/PcRGB/raw/main/Fritzing/Schematics.fzz>
