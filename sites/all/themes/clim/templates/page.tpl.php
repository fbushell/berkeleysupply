<div class="wrapper">
<nav id="nav">
  <a href="html">Home</a>
  <span>.</span>
  <a href="#about">About</a>
  <span>.</span>
  <a href="#brands">Brands</a>
  <span>.</span>
  <a href="#footer">Visit</a>
  <span>.</span>
  <a href="//blog.berkeleysupply.com" target="_blank">Blog</a>
</nav>
<header id="header">
	<div class="container">
   <div id="logo"> 
    <a href="<?php print $front_page; ?>">
      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
    </a>
  </div>
	</div>
</header>

<div class="content" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print $messages; ?>
    <?php print render($page['content']) ?>
</div>
<!-- <div class="stripe-top"></div>
<div class="stripe-right"></div>
<div class="stripe-bottom"></div>
<div class="stripe-left"></div> -->
