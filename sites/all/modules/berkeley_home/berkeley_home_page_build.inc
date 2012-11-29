<?php
/**
* @file
*
* Build homepage
*
*/

function berkeley_home_page_build(){

	// Init vars
	$module_path = drupal_get_path('module','berkeley_home');
	$html = '';
	
	
	 // Build MySQL Query Statement
  $about_query_string = "
     SELECT about_page_text, about_page_vimeo_id, id
      FROM cirro_about_page
      WHERE id = 1
  ";
  

  // Use drupal's db_query function 
  // $about_query = db_query( $about_query_string );
  // $about_items = $about_query->fetchAssoc();

	
	// Adding javascript for fitvid
	//$js_path = "$module_path/js/jquery.fitvids.js";
	//drupal_add_js($js_path);

	$html = "
		<div class=\"content\">
			<div class=\"about\">
				<p>Yo this is the store, what of it</p>
			</div>
		</div>
	";
	

	return $html; 

}