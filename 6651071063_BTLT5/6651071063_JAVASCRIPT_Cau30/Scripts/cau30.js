function insert_Row() {
  var t = document.getElementById("sampleTable");
  var n = t.rows.length + 1;
  var row = t.insertRow(t.rows.length);
  row.insertCell(0).innerHTML = "Row" + n + " cell1";
  row.insertCell(1).innerHTML = "Row" + n + " cell2";
}
