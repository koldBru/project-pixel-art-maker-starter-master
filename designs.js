function addRow(tableID) {
  // Get a reference to the table
  let table = document.getElementById('pixelCanvas');

  // Insert a row at the end of the table
  let newRow = table.insertRow(x);

  // Insert a cell in the row at index 0
  let newCell = newRow.insertCell(y);

  // Append a text node to the
}


const color = document.getElementById('colorPicker');
const sizePicker = document.getElementById('sizePicker');
const table = document.getElementById('pixelCanvas');
// The heigh and width input
var width = document.getElementById('inputWidth').value;
var height = document.getElementById('inputHeight').value;
// TODO: here link the width Eelemet also
sizePicker.addEventListener('click', (event) => {
    event.preventDefault();
    width = document.getElementById('inputWidth').value;
    height = document.getElementById('inputHeight').value;
    // TODO: clear table first to redraw the new table.
    makeGrid(height, width)
});
// When size is submitted by the user, call makeGrid()
function makeGrid(height, width) {
    // this is the make grid loop

    for(var x = 0; x < height; x++){
        function addRow(table){
        table.appendChild(newRow);
      };

      // TODO: here you need to insert row to the table and assign its row index.

        for(var y = 0; y < width; y++){
        };
            // TODO: you need to insert cell to the table and assign its column index.

            // TODO: and then you need to add Click event listener to cell, and inside the event function assign the background style cell to color value of colorPicker element

        }
    }
