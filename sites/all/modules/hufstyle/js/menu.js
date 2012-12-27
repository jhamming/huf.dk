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

jQuery(window).load(function () {
	//Manipulate facebook box width. Since the iframe has no ID i need to match on the source attribute
	var facebookIframe = new Array();
	facebookIframe = jQuery('iframe');
	for(var i=0;i<facebookIframe.length;i++){
		var facebookMatch=facebookIframe[i].src.match(/facebook/g);
		if (facebookMatch !== undefined) {
			facebookIframe[i].setAttribute("style","border:none; overflow:hidden; width:100%; height:690px;");
		}
	}
});