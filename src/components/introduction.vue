<template>
  <div >

    <div class="row mt-3">
      <h1 class="p-0 m-0" style="color: rebeccapurple">sorts compare</h1>
    </div>

    <hr>

    <div class="row mt-2 p-0  ">
      <div class="col-6  ">
        <div class="row d-flex flex-column justify-content-center  ">
          <img src="../assets/images/photo_2021-04-03_18-53-42.jpg" style="align-self: center" >
        </div>

        <div class="row mt-2 p-0">
          <p class="m-0 p-0">

            <span style="font-weight: bold">Ali Irvani </span> (back) <br>
            <span style="color: coral">Known as </span> : <a href="https://github.com/okabe-rintaru"> okabe-rintaru </a>
          </p>
        </div>
      </div>


      <div class="col-6  ">
        <div class="row d-flex flex-column justify-content-center ">
          <img src="../assets/images/photo_2021-04-03_22-37-0222.jpg"  style="align-self: center">
        </div>
        <div class="row mt-2 p-0  ">
          <p class="m-0 p-0">
            <span style="font-weight: bold">Shahab Shafie </span>   (front + back) <br>
            <span style="color: coral"> Known as : </span><a href="https://github.com/Shhb-Coder-1999" >  Shhb-Coder-1999 </a>
          </p>
        </div>
      </div>

    </div>

    <hr>

    <div class="row mt-2 px-3  ">
      <b-progress class=" w-100 p-0">
        <b-progress-bar :value="25" variant="success" animated striped  >vue</b-progress-bar>
        <b-progress-bar :value="25" variant="info"  animated striped  >c++</b-progress-bar>
        <b-progress-bar :value="25" variant="danger" animated striped   >html</b-progress-bar>
        <b-progress-bar :value="25" variant="warning" animated striped   >JS</b-progress-bar>
      </b-progress>

    </div>

    <hr>

    <div class="row mt-3">
      <p class="m-0 p-0">
         <span style="color: coral">Professor : </span> <a href="https://www.linkedin.com/in/mehdi-salkhordeh-haghighi-2a339a1a/"> Mr.Salkhorde haghighi</a> <br>
         <span style="color: coral">TA :  </span><a href="https://www.linkedin.com/in/payam-kiyani-pk3440/"> Mr.Kiani </a><br>
         <span style="color: coral">University : </span> Iran , Mashhad , <a href="https://en.wikipedia.org/wiki/Sadjad_University_of_Technology"> Sadjad University of Technology </a> <br>
         <span style="color: coral">Released time : </span> 8 Apr 2021
        
      </p>
    </div>

    <hr>

    <div class="row mt-3 px-3">
      <p style="font-size: 10px" class="p-0 m-0">
       <span style="color: red">brief summary about project : </span>  <br>
        The Heapsort algorithm involves preparing the list by first turning it into a max heap. The algorithm then repeatedly swaps the first value of the list with the last value, decreasing the range of values considered in the heap operation by one, and sifting the new first value into its position in the heap. This repeats until the range of considered values is one value in length.

      </p>
    </div>

    <hr class="mb-0">

    <div class="row mt-1 mb-2 ">
      <a href="https://github.com/okabe-rintaru/heap-Sorts-Comparison" class="p-0 m-0"><img src="../assets/images/GitHub-Mark.png" class="p-0 m-0 github"></a>
<!--      <p style="font-size: 11px">-->
<!--        Project Src : <a href="https://github.com/okabe-rintaru/heap-Sorts-Comparison">https://github.com/okabe-rintaru/heap-Sorts-Comparison</a>-->
<!--      </p>-->
    </div>



  </div>
</template>




<script>


export default {


  data() {
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

img{
  height: 70px;
  width: auto;
  border-radius: 50%;
}

.github {
  height: 50px;
  width: auto;
  border-radius: 50%;
}

/*div {*/
/*  border: #2c3e50;*/
/*  border-style: solid;*/
/*  border-width: 1px;*/
/*}*/

p {
  font-size: 11px;
}

h1{
  font-size: 25px;
}

a{
  text-decoration: none;
  color: currentColor;
}

a:hover {
  color: rebeccapurple;
  text-decoration: underline;
}

</style>
