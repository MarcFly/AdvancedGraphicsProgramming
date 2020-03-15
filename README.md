Zurullito Painter is a basic tool to draw using shapes along an basic Hierarchical System.

**Features:**
- Add Entities such as Squares, Circles and Lines
- Move them around by clicking and dragging them
- Change the scale and rotat them using the inspector
- Observe that hierarchy transformations are applied through parenting!
- And obviously, at any time you can reorder the hierarchy, although I would recommend not reordering too fast...
- Create, Save and Open files in the exclusive AWOOGA file format.
- Render your creation to a PNG or JPG file, you choose
  - The painting will be the size of the current Canvas, so move the scene around until you find that your creation fits it perfectly.

**Use of Signals and Slots:**
In a way to get to know the Qt system for callbacks, no Dock widgets and entities interact directly between them.
Everything is setup through signal->signal or signal->slot connections.
The objective is to have this signals being caught by the modules/widgets interested in the data, making it easier to share it.

The only resources used are the icons which are in the icons folder and can be visually seen on the app.

Finally, as a special addition, a new canvas widget was added as a way to visualize the outcome of the selected fill or outline options.
At the same time, this small canvas acts as a Color Dialog trigger which will allow you to select the desired color.

**This app has been created by Marc Torres - 15/03/2020**

**As the rest of the repo, this falls under MIT License so have fun tinkering with it!**
