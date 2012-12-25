jQuery(window).load(function () {

		// Create the dropdown base
		jQuery("<select />").appendTo("nav");
		// Create default option "Go to..."
		jQuery("<option />", {
		   "selected": "selected",
		   "value"   : "",
		   "text"    : "Gå til..."
		}).appendTo("nav select");

		// Populate dropdown with menu items
		jQuery("nav a").each(function() {
		 var el = jQuery(this);
		 jQuery("<option />", {
		     "value"   : el.attr("href"),
		     "text"    : el.text()
		 }).appendTo("nav select");
		});

		jQuery("nav select").change(function() {
		  window.location = jQuery(this).find("option:selected").val();
		});
});
