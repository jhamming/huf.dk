/* Removes the ask toolbar that breaks layout in Chrome */
jQuery(window).load(function () {
    if(document.getElementById("apn-null-toolbar") != null){
        // mainMenu had a style change for its top positioning, returning it to normal
        // perhaps a function can be made which iterates over every element ask has changed
        document.getElementById("mainMenu").style.top = "-16px";
        // Just remove the iframe and style elements
        (elem=document.getElementById("apn-null-toolbar")).parentNode.removeChild(elem);
        (elem=document.getElementById("apn-body-style")).parentNode.removeChild(elem);
    }
});