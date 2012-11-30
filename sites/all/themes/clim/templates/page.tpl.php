<div class="wrapper">
<header id="header">
	<div class="container">
    <a href="<?php print $front_page; ?>" id="logo">
      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
    </a>
  <nav id="nav">
  	<a href="#footer">Footer</a>
  </nav>
	</div>
</header>

<div class="content" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print $messages; ?>
    <?php print render($page['content']) ?>
   	<div id="main-scroller" data-stellar-background-ratio="0.5">
    	
    </div>
</div>
<div class="stripe-top"></div>
<div class="stripe-right"></div>
<div class="stripe-bottom"></div>
<div class="stripe-left"></div>

<footer id="footer">
  <div class="container">
  </div>
</footer> 