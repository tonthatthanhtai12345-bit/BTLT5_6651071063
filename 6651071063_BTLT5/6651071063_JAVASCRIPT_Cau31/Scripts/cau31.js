function removecolor() {
  var s = document.getElementById("colorSelect");
  if (s.options.length > 0) s.remove(s.selectedIndex);
}
